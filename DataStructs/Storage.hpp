template <typename K,typename V> class Storage{
	public:
	virtual void insert(K key,V value)	=0;
	virtual V* find(K key)			=0;
	virtual void remove(K key)		=0;
	virtual unsigned long getSize()		=0;
};
