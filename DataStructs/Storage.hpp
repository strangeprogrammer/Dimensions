#ifndef STORAGE_HPP
#define STORAGE_HPP

template <typename K,typename V> class Storage{
	public:
	virtual void insert(KVP<K,V> pair)	=0;
	virtual void insert(K key,V value)	=0;
	virtual V* find(K key)			=0;
	virtual V* remove(K key)		=0;
	virtual KVP<K,V>* rmmin()		=0;
	virtual KVP<K,V>* rmmax()		=0;
	virtual void purge()			=0;
	virtual unsigned long getSize()		=0;
};

#endif //STORAGE_HPP
