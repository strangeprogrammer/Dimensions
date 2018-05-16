#ifndef KVP_HPP
#define KVP_HPP

template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	long compareTo(const KVP<K,V>& against){
		if(key<(against.key)){
			return -1;
		}else if((against.key)<key){
			return 1;
		}else{
			return 0;
		}
	}
	
	KVP(K key,V value){
		this->key=key;
		this->value=value;
	}
	
	KVP(const KVP<K,V>& orig):KVP(orig.key,orig.value){}
	
	KVP(){}
	
	~KVP(){}
};

#endif //KVP_HPP
