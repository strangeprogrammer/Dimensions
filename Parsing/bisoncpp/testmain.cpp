#include "all.hpp"

using namespace std;

int main(){
	Parser parser;
	if(parser.parse()){
		cout << "STRING REJECTED" << endl;
		return 1;
	}
	cout << "STRING ACCEPTED" << endl;
	return 0;
}
