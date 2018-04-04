#ifndef KVP_HPP
#define KVP_HPP

template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	virtual long compareTo(KVP<K,V>* against){
		return key-(against->key);
	}
	
	virtual long unlock(K key){
		return (this->key)-key;
	}
	
	KVP(K key,V value):key(key),value(value){}
	KVP()=default;
};

#endif //KVP_HPP
