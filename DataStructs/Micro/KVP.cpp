template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	
	long compare(K key){
		return (this->key)-key;
	}
	
	//KVP();//TODO: Make this throw an error
	
	KVP(K key,V value):key(key),value(value);
	//~KVP();//TODO: Implement this
};
