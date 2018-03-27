template <typename K,typename V> class KVP{
	public:
	K key;
	V value;
	long compare(K key);
	KVP(K key,V value);
	~KVP();//TODO: Implement this
};
