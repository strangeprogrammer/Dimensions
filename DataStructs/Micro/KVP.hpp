#ifndef KVP_HPP
#define KVP_HPP

template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	long compareTo(KVP<K,V>* against){
		return key-(against->key);
	}
	
	bool unlock(K key){
		return !((this->key)-key);
	}
	
	KVP(K key,V value){
		this->key=key;
		this->value=value;
	}
	
	KVP(){}
	
	~KVP(){}
};

#endif //KVP_HPP
