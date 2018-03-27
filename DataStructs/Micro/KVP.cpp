template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	long compare(K key){
		return (this->key)-key;
	}
	
	KVP(K key,V value):key(key),value(value);
	
	~KVP();
};
