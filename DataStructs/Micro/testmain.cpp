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
	cout << endl << "hi.value ";
	cin >> hi.value;
	cout << endl << "bye.key ";
	cin >> bye.key;
	cout << endl << "bye.value ";
	cin >> bye.value;
	cout << endl;
	
	cout << hi.compareTo(&bye) << endl;
	return 0;
}
