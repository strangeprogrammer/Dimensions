#include <iostream>
#include "all.hpp"

using namespace std;

/*
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
*/

int main(){
	KVP<int,int> hi=KVP<int,int>(0,0);
	KVP<int,int> bye=KVP<int,int>(0,0);
	
	cout << "hi.key ";
	cin >> hi.key;
	cout << "hi.value ";
	cin >> hi.value;
	cout << "bye.key ";
	cin >> bye.key;
	cout << "bye.value ";
	cin >> bye.value;
	
	cout << hi.compareTo(&bye) << endl << hi.key << " " << hi.value << endl << bye.key << " " << bye.value;
	return 0;
}
