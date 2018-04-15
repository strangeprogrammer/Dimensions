#ifndef LIST_HPP
#define LIST_HPP

namespace Linear{
	//This is a very dumb linked list for testing purposes
	#define PAIR KVP<K,V>
	template <typename K,typename V> class List:public Storage<K,V>{
		private:
		Tube<PAIR> t;
		
		void locate(K key){
			PAIR temp;
			for(unsigned long i=0;i<getSize();i++){
				t.backpush(temp=t.frontpop());
				if(temp.unlock(key)){
					break;
				}
			}
			return;
		}
		
		public:
		virtual void insert(K key,V value){
			t.frontpush(PAIR(key,value));
			return;
		}
		
		virtual V* find(K key){
			V* retval=NULL;
			if(getSize()){
				locate(key);
				PAIR temp=t.backpop();
				if(temp.unlock(key)){
					retval=&(temp.value);
				}
				t.frontpush(temp);
			}
			return retval;
		}
		
		virtual void remove(K key){
			if(getSize()){
				locate(key);
				PAIR temp=t.backpop();
				if(!temp.unlock(key)){
					t.frontpush(temp);
				}
			}
			return;
		}
		
		virtual PAIR* rmrandom(){
			PAIR* retval=NULL;
			if(getSize()){
				retval=new PAIR();
				*retval=t.backpop();
			}
			return retval;
		}
		
		virtual void purge(){
			t.purge();
			return;
		}
		
		virtual unsigned long getSize(){
			return t.getSize();
		}
		
		virtual ~List(){}
	};
	#undef PAIR
}

#endif //LIST_HPP
