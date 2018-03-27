#include "all.hpp"

namespace Linear{
	template <typename T> class Tube{
		public:
		void frontpush(T datum);
		T frontpop();
		T frontpeek();
		void backpush(T datum);
		T backpop();
		T backpeep();
		//This function serves as an API call, an optimization layer, and an error checking layer on top of 'actualRoll'
		void roll(long hops);
		unsigned long getSize();
		Tube();
		~Tube();
	};
	
	template <typename K,typename V> class LL:public Storage<K,V>,private Tube<KVP<K,V>*>{
		public:
		void insert(KVP<K,V>* toinsert);
		//A dumb find algorithm (for testing purposes)
		KVP<K,V>* find(K key);
		KVP<K,V>* remove(K key);
		unsigned long getSize();
		LL();
		~LL();
	};
}
