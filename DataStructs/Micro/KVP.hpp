template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	long compareTo(KVP<K,V>* against){
		return key-(against->key);
	}
	
	long unlock(K key){
		return (this->key)-key;
	}
	
	KVP(K key,V value):key(key),value(value){}
	KVP(){}
	
	~KVP(){}
};
