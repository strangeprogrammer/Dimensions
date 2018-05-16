#ifndef LIST_HPP
#define LIST_HPP

namespace Linear{
	//This is a very dumb linked list for testing purposes
	#define PAIR KVP<K,V>
	template <typename K,typename V> class List:public Storage<K,V>{
		private:
		Tube<PAIR> l,r;
		
		//For all locating functions, the front of 'l' will contain the closest key less than or equal to the given key (if any)
		
		void up(K key){
			PAIR temp;
			while(r.getSize()){
				temp=r.frontpop();
				if(temp.key<=key){
					l.frontpush(temp);
				}else{
					r.frontpush(temp);
					break;
				}
			}
		}
		
		void down(K key){
			PAIR temp;
			while(l.getSize()){
				temp=l.frontpop();
				if(key<temp.key){
					r.frontpush(temp);
				}else{
					l.frontpush(temp);
					return;
				}
			}
		}
		
		void locate(K key){
			if(l.getSize()){
				PAIR temp=l.frontpop();
				if(temp.key<key){
					l.frontpush(temp);
					up(key);
				}else if(key<temp.key){
					r.frontpush(temp);
					down(key);
				}else{
					l.frontpush(temp);
				}
			}else{
				up(key);
			}
		}
		
		inline void locatemin(){
			while(l.getSize()){
				r.frontpush(l.frontpop());
			}
			if(r.getSize()){
				l.frontpush(r.frontpop());
			}
		}
		
		inline void locatemax(){
			while(r.getSize()){
				l.frontpush(r.frontpop());
			}
		}
		
		public:
		void insert(PAIR pair){
			locate(pair.key);
			l.frontpush(pair);
		}
		
		void insert(K key,V value){
			insert(typename PAIR::KVP(key,value));
		}
		
		V* find(K key){
			locate(key);
			if(l.getSize()){
				PAIR temp=l.frontpeek();
				if(temp.key==key){
					V* retval=new V();
					*retval=temp.value;
					return retval;
				}
			}
			return NULL;
		}
		
		V* remove(K key){
			V* retval=find(key);
			if(retval!=NULL){
				l.frontpop();
			}
			return retval;
		}
		
		PAIR* rmmin(){
			locatemin();
			if(l.getSize()){
				return new PAIR(l.frontpop());
			}
			return NULL;
		}
		
		PAIR* rmmax(){
			locatemax();
			if(l.getSize()){
				return new PAIR(l.frontpop());
			}
			return NULL;
		}
		
		void purge(){
			l.purge();
			r.purge();
			return;
		}
		
		unsigned long getSize(){
			return l.getSize()+r.getSize();
		}
		
		List():l(),r(){}
	};
	#undef PAIR
}

#endif //LIST_HPP
