#include "all.hpp"

//Test string: (aA>zA<)(&F#F~F@)(#~@)(0987654321+)(0-)(%)(£)($)([)([)([)(1-)(])(])(])([)(])(/)

using namespace std;
using namespace ExecBlocks;
using namespace Node;
using namespace Details;

void printAxes(Axes* toprint){
	KVP<unsigned long,long>* temp;
	unsigned long k;
	long v;
	Axes* backup=new Axes();
	while(temp=toprint->rmrandom()){
		backup->insert(k=temp->key,v=temp->value);
		delete temp;
		cout << endl << "\t" << ((char)k) << " " << v;
	}
	while(temp=backup->rmrandom()){
		toprint->insert(temp->key,temp->value);
		delete temp;
	}
	delete backup;
}

int main(){
	Parser parser;
	cout << "Enter Program Here: ";
	bool retval=!parser.parse();
	
	Node::DLN<InstructionType>	*start=Globals::env.package(),
					*temp;
	
	while(start!=NULL){
		if(retval){
			cout << start << " ";
			switch (start->datum){
				case ADD:
					cout << "ADD: " << (((add*)start)->d->value);
					break;
				case SUB:
					cout << "SUB: " << (((sub*)start)->d->value);
					break;
				case HALT:
					cout << "HALT";
					break;
				case GETC:
					cout << "GETC";
					break;
				case PUTN:
					cout << "PUTN";
					break;
				case PUTC:
					cout << "PUTC";
					break;
				case NOOP:
					cout << "NOOP";
					break;
				case TZJ:
					cout << "TZJ: " << (((tzj*)start)->d->target);
					break;
				case JMP:
					cout << "JMP: " << (((jmp*)start)->d->target);
					break;
				case MOV:
					cout << "MOV:";
					printAxes(((mov*)start)->d);
					break;
				case STRV:
					cout << "STRV:";
					printAxes(((strv*)start)->d);
					break;
				case SETV:
					cout << "SETV:";
					printAxes(((setv*)start)->d);
					break;
			}
			cout << endl;
		}
		temp=start->succ;
		delete start;
		start=temp;
	}
	return 0;
}
