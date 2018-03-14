template <typename K,typename V> class Storage{
	public:
	virtual long insert(K key,V value)	=0;
	virtual V find(K key)			=0;
	virtual long remove(K key)		=0;
};
