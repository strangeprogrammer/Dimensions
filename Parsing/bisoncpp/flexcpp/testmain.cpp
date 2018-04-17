#include "Scanner.hpp"

using namespace std;

int main(){
	Scanner scanner;
	int temp=true;
	while(temp=scanner.lex()){
		cout << temp << ": " << scanner.matched() << endl;
	}
	return 0;
}
