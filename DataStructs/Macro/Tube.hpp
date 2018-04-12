namespace Linear{
	/* This is basically an amalgamation of a queue, stack, and ring buffer
	 * Any changes are intended to affect only pointers of internal nodes where possible (gives best big-O time when copying structures with many fields)
	 * 
	 * Notes:
	 * The functions frontpop, frontpeek, backpop, and backpeek throw '1' on underflow (you're on your own when you're out of memory)
	 * Pointers to all elements are lost upon destruction, so be careful to garbage collect properly!
	 * Not Multithread-Safe
	 */
	#define DLN Node::DLN
	template <typename T> class Tube{
		private:
		DLN<T>* crux;
		unsigned long elements;
		
		//Returns the insertion point for rolling, not the node that one would actually hop to
		inline DLN<T>* hop(long hops){
			DLN<T>* point=crux;
			if(hops<0){//Scoot back 1 so that crux can be re-inserted properly
				point=point->prev;
			}
			for(;hops<0;hops++,point=point->prev);
			for(;0<hops;hops--,point=point->succ);
			return point;
		}
		
		//Positive hops move elements from the front to the back and negative hops do the opposite
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
			return crux->succ->datum;
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
		
		T backpeek(){
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
			if(hops==0){//No change means no work to do!
				return;
			}
			if((elements+1)/2<std::llabs(hops)){//Optimized since rolling more than halfway is the same as rolling backward less than halfway
				if(0<hops){
					hops-=elements;
				}else{
					hops+=elements;
				}
			}
			actualRoll(hops);//Using amount of actual hops
			return;
		}
		
		virtual unsigned long getSize(){
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
	#undef DLN
}
