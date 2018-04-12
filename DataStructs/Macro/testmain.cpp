#include <iostream>
#include "all.hpp"

/*
namespace Linear{
	template <typename T> class Tube{
		public:
		void frontpush(T datum);
		T frontpop();
		T frontpeek();
		void backpush(T datum);
		T backpop();
		T backpeep();
		void roll(long hops);
		unsigned long getSize();
		virtual void purge();
		Tube();
		~Tube();
	};
	
	#define PAIR KVP<K,V*>
	#define SUPER Tube<PAIR>
	template <typename K,typename V> class List:public Storage<K,V>,private SUPER{
		public:
		virtual void insert(K key,V value);
		virtual V* find(K key);
		virtual void remove(K key);
		virtual void purge();
		virtual unsigned long getSize();
		List();
		~List();
	};
	#undef SUPER
	#undef PAIR
}
*/

using namespace std;
using namespace Linear;

int main(){
	Tube<int> t=Tube<int>();
	
	cout << "Initial Tube size:         " << t.getSize()		<< endl;
	
	t.frontpush(283);
	cout << "Pushed 283 onto front" << endl;
	
	cout << "Tubesize Now:              " << t.getSize()		<< endl;
	cout << "Front value:               " << t.frontpeek()		<< endl;
	cout << "Again:                     " << t.frontpeek()		<< endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	cout << "Front value removed:       " << t.frontpop()		<< endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	
	t.frontpush(4574);
	cout << "Pushed 4574 onto front" << endl;
	cout << "Tubesize Now:              " << t.getSize()		<< endl;
	
	cout << "Back value:                " << t.backpeep()		<< endl;
	cout << "Again:                     " << t.backpeep()		<< endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	cout << "Back value removed:        " << t.backpop()		<< endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	
	t.frontpush(0);
	cout << "Pushed 0 onto front" << endl;
	t.backpush(-1);
	cout << "Pushed -1 onto back" << endl;
	t.frontpush(1);
	cout << "Pushed 1 onto front" << endl;
	t.backpush(-2);
	cout << "Pushed -2 onto back" << endl;
	t.frontpush(2);
	cout << "Pushed 2 onto front" << endl;
	
	cout << "Size:                      " << t.getSize()		<< endl;
	
	cout << "Popped from front:         " << t.frontpop()		<< endl;
	cout << "Popped from front:         " << t.frontpop()		<< endl;
	cout << "Popped from front:         " << t.frontpop()		<< endl;
	cout << "Popped from front:         " << t.frontpop()		<< endl;
	cout << "Popped from front:         " << t.frontpop()		<< endl;
	
	cout << "Size:                      " << t.getSize()		<< endl;
	
	t.frontpush(0123);
	t.frontpush(0123);
	t.frontpush(0123);
	t.frontpush(0123);
	cout << "Pushed 0123 onto front 4 times" << endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	
	t.purge();
	cout << "Purged all elements" << endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	
	t.frontpush(0);
	t.frontpush(1);
	t.frontpush(2);
	t.frontpush(3);
	cout << "Pushed 0 1 2 3 onto front" << endl;
	cout << "Size:                      " << t.getSize()		<< endl;
	
	int helper;
	
	t.roll(0);
	cout << "Rolled 0" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(1);
	cout << "Rolled 1" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(2);
	cout << "Rolled 2" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(3);
	cout << "Rolled 3" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(4);
	cout << "Rolled 4" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(5);
	cout << "Rolled 5" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(-5);
	cout << "Rolled -5" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(-4);
	cout << "Rolled -4" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(-3);
	cout << "Rolled -3" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(-2);
	cout << "Rolled -2" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	t.roll(-1);
	cout << "Rolled -1" << endl;
	
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	cout << "Popped from back to front: " << (helper=t.backpop())	<< endl;t.frontpush(helper);
	
	List<int,int> l=List<int,int>();
	cout << "Initial List size:         " << l.getSize()		<< endl;
	
	l.insert(5,20);
	cout << "Inserted K=5:V=20" << endl;
	cout << "Size:                      " << l.getSize()		<< endl;
	
	cout << "Found K=5:                 " << *(l.find(5))		<< endl;
	
	l.remove(5);
	cout << "Removed K=5" << endl;
	cout << "Size:                      " << l.getSize()		<< endl;
	
	l.insert(0,1);
	l.insert(2,3);
	l.insert(4,5);
	l.insert(6,7);
	cout << "Inserted K=0:V=1 K=2:V=3 K=4:V=5 K=6:V=7" << endl;
	cout << "Size:                      " << l.getSize()		<< endl;
	
	l.purge();
	cout << "Purged everything" << endl;
	cout << "Size:                      " << l.getSize()		<< endl;
	
	return 0;
}
