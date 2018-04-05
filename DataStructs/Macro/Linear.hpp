namespace Linear{
	using namespace Node;
	/* This is basically an amalgamation of a queue, stack, and ring buffer
	 * Any changes are intended to affect only pointers of internal nodes where possible (gives best big-O time when copying structures with many fields)
	 * 
	 * Notes:
	 * The functions frontpop, frontpeek, backpop, and backpeep throw '1' on underflow (you're on your own when you're out of memory)
	 * Pointers to all elements are lost upon destruction, so be careful to garbage collect properly!
	 * Not Multithread-Safe
	 */
	template <typename T> class Tube{
		private:
		DLN<T>* crux;
		unsigned long elements;
		
		//Returns the insertion point for rolling, not the node that one would actually hop to
		inline DLN<T>* hop(long hops){
			DLN<T>* point=crux;
			if(hops<0){//Progress backward
				for(;hops;
				hops--,point=point->prev);
				point=point->prev;
			}else{//Progress forward
				for(;hops;
				hops--,point=point->next);
			}
			return point;
		}
		
		//Positive hops move elements from the front to the back
		inline void actualRoll(long hops){
			DLN<T>* point=hop(hops);	//Get node to insert after
			crux->prev->spliceSucc();	//Remove crux
			point->appendSucc(crux);	//Put crux in the right place
			return;
		}
		
		public:
		void frontpush(T datum){
			crux->appendSucc(new DLN<T>(datum));
			elements++;
			return;
		}
		
		T frontpop(){
			if(elements==0){//EmptyNote: The '==0' is nessecary since otherwise there'd be a return statement mess
				throw 1;
			}
			DLN<T>* temp=crux->spliceSucc();
			elements--;
			T retval=temp->datum;
			delete temp;
			return retval;
		}
		
		T frontpeek(){
			if(elements==0){//See comment 'EmptyNote'
				throw 1;
			}
			return crux->next->datum;
		}
		
		void backpush(T datum){
			crux->prev->appendSucc(new DLN<T>(datum));
			elements++;
			return;
		}
		
		T backpop(){
			if(elements==0){//See comment 'EmptyNote'
				throw 1;
			}
			DLN<T>* temp=crux->prev->prev->spliceSucc();
			elements--;
			T retval=temp->datum;
			delete temp;
			return retval;
		}
		
		T backpeep(){
			if(elements==0){//See comment 'EmptyNote'
				throw 1;
			}
			return crux->prev->datum;
		}
		
		//This function serves as an API call, an optimization layer, and an error checking layer on top of 'actualRoll'
		void roll(long hops){
			if(elements==0){
				return;
			}
			hops=hops%elements;//Amount of logical hops (prevents caller from messing with everything)
			if(!hops){//No change means no work to do!
				return;
			}
			if((elements+1)/2<std::abs(hops)){//Optimize since rolling more than halfway is the same as rolling backward less than halfway
				if(0<hops){
					hops-=elements;
				}else{
					hops+=elements;
				}
			}
			actualRoll(hops);//Using amount of actual hops
			return;
		}
		
		unsigned long getSize(){
			return elements;
		}
		
		virtual void purge(){
			for(;elements;elements--){
				delete crux->spliceSucc();
			}
			return;
		}
		
		Tube():crux(new DLN<T>()),elements(0){
			crux->appendSucc(crux);
			return;
		}
		
		~Tube(){
			purge();
			delete crux;
			return;
		}
	};
	
	#define PAIR KVP<K,V*>
	#define SUPER Tube<PAIR>
	template <typename K,typename V> class LL:public Storage<K,V>,private SUPER{
		private:
		using SUPER::frontpush;
		using SUPER::frontpop;
		using SUPER::backpush;
		using SUPER::backpop;
		using SUPER::getSize;
		void locate(K key){
			PAIR temp;
			for(unsigned long i=0;i<getSize();i++){
				backpush(temp=frontpop());
				if(temp.unlock(key)==0){
					break;
				}
			}
			return;
		}
		
		public:
		virtual void insert(K key,V value){
			V* toinsert=new V();
			*toinsert=value;
			frontpush(PAIR(key,toinsert));
			return;
		}
		
		//A dumb find algorithm (for testing purposes, mostly)
		virtual V* find(K key){
			V* retval=NULL;
			locate(key);
			PAIR temp=backpop();
			if(temp.unlock(key)==0){
				retval=temp.value;
			}
			frontpush(temp);
			return retval;
		}
		
		virtual void remove(K key){
			locate(key);
			PAIR temp=backpop();
			if(temp.unlock(key)==0){
				delete temp.value;
			}else{
				frontpush(temp);
			}
			return;
		}
		
		virtual void purge(){
			SUPER::purge();
			return;
		}
		
		virtual unsigned long getSize(){
			return SUPER::getSize();
		}
		
		LL():SUPER::Tube(){}
		
		virtual ~LL(){
			return;
		}
	};
	#undef SUPER
	#undef PAIR
}
