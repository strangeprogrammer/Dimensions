//This is a very dumb linked list for testing purposes
#define PAIR KVP<K,V>
#define SUPER Tube<PAIR>
template <typename K,typename V> class List:public Storage<K,V>,private SUPER{
	private:
	using SUPER::frontpush;
	using SUPER::frontpop;
	using SUPER::backpush;
	using SUPER::backpop;
	
	void locate(K key){
		PAIR temp;
		for(unsigned long i=0;i<getSize();i++){
			backpush(temp=frontpop());
			if(temp.unlock(key)){
				break;
			}
		}
		return;
	}
	
	public:
	virtual void insert(K key,V value){
		frontpush(PAIR(key,value));
		return;
	}
	
	virtual V* find(K key){
		V* retval=NULL;
		if(getSize()){
			locate(key);
			PAIR temp=backpop();
			if(temp.unlock(key)){
				retval=&(temp.value);
			}
			frontpush(temp);
		}
		return retval;
	}
	
	virtual void remove(K key){
		if(getSize()){
			locate(key);
			PAIR temp=backpop();
			if(!temp.unlock(key)){
				frontpush(temp);
			}
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
	
	List():SUPER::Tube(){}
	
	virtual ~List(){}
};
#undef SUPER
#undef PAIR
