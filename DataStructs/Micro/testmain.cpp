#include <iostream>
#include "all.hpp"

using namespace std;

int main(){
	KVP<int,int> paira=KVP<int,int>(0,0);
	KVP<int,int> pairb=KVP<int,int>(0,0);
	
	paira.key=50;
	paira.value=3;
	pairb.key=40;
	pairb.value=2;
	
	cerr <<
	"paira.key:               " << paira.key		<< endl <<
	"paira.value:             " << paira.value		<< endl <<
	"pairb.key:               " << pairb.key		<< endl <<
	"pairb.value:             " << pairb.value		<< endl <<
	"paira.compareTo(&pairb): " << paira.compareTo(&pairb)	<< endl;
	
	using namespace Node;
	
	SLN<int> slna=SLN<int>(2);
	SLN<int> slnb=SLN<int>(&slna,1);
	SLN<int> slnc=SLN<int>(&slnb,0);
	
	slna.appendSucc(slnc.spliceSucc());
	
	//C->A->B
	
	cerr <<
	"slnc:       " << &slnc		<< endl <<
	"slnc.datum: " << slnc.datum	<< endl <<
	"slnc.succ:  " << slnc.succ	<< endl <<
	"slna:       " << &slna		<< endl <<
	"slna.datum: " << slna.datum	<< endl <<
	"slna.succ:  " << slna.succ	<< endl <<
	"slnb:       " << &slnb		<< endl <<
	"slnb.datum: " << slnb.datum	<< endl <<
	"slnb.succ:  " << slnb.succ	<< endl;
	
	
	DLN<int> dlna=DLN<int>(0);
	DLN<int> dlnb=DLN<int>(1);
	DLN<int> dlnc=DLN<int>(2);
	
	dlnc.appendSucc(dlna.appendSucc(&dlna)->appendSucc(&dlnb)->appendSucc(&dlnc)->spliceSucc());
	
	//A<->B<->C
	
	cerr <<
	"dlna.prev:  " << dlna.prev	<< endl <<
	"dlna:       " << &dlna		<< endl <<
	"dlna.datum: " << dlna.datum	<< endl <<
	"dlna.succ:  " << dlna.succ	<< endl <<
	"dlnb.prev:  " << dlnb.prev	<< endl <<
	"dlnb:       " << &dlnb		<< endl <<
	"dlnb.datum: " << dlnb.datum	<< endl <<
	"dlnb.succ:  " << dlnb.succ	<< endl <<
	"dlnc.prev:  " << dlnc.prev	<< endl <<
	"dlnc:       " << &dlnc		<< endl <<
	"dlnc.datum: " << dlnc.datum	<< endl <<
	"dlnc.succ:  " << dlnc.succ	<< endl;
	
	using namespace Details;
	
	Axes fiftytwo=Axes(52);
	Axes one=Axes(1);
	Number num=Number(10);
	InstructionTemp<ADD,Number> itemp=InstructionTemp<ADD,Number>();
	Jump jumpa=Jump();
	Jump jumpb=Jump(&itemp);
	
	cerr << "*(fiftytwo.find(51)): " << *(fiftytwo.find(51)) << endl;
	cerr << "fiftytwo.find(52): " << fiftytwo.find(52) << endl;
	
	cerr << "*(one.find(0)): " << *(one.find(0)) << endl;
	cerr << "one.find(1): " << one.find(1) << endl;
	
	fiftytwo.set(51,8);
	cerr << "*(fiftytwo.find(51)): " << *(fiftytwo.find(51)) << endl;
	
	fiftytwo.set(52,3);
	cerr << "*(fiftytwo.find(52)): " << *(fiftytwo.find(52)) << endl;
	
	cerr << "num.value: " << num.value << endl;
	
	num.value=5;
	
	cerr << "num.value: " << num.value << endl;
	
	cerr << "&itemp: " << &itemp << endl;
	cerr << "jumpa.target: " << jumpa.target << endl;
	cerr << "jumpb.target: " << jumpb.target << endl;
	
	return 0;
}
