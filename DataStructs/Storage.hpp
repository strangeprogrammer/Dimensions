template <typename K,typename V> class Storage{
	public:
	virtual void insert(KVP<K,V>* toinsert)	=0;
	virtual KVP<K,V>* find(K key)		=0;
	virtual KVP<K,V>* remove(K key)		=0;
};
