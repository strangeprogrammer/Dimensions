#include "all.hpp"

using namespace std;

int main(){
	KVP<int,int> paira=KVP<int,int>(0,0);
	KVP<int,int> pairb=KVP<int,int>(0,0);
	
	paira.key=50;
	paira.value=3;
	pairb.key=40;
	pairb.value=2;
	
	cout <<
	"paira.key:               " << paira.key		<< endl <<
	"paira.value:             " << paira.value		<< endl <<
	"pairb.key:               " << pairb.key		<< endl <<
	"pairb.value:             " << pairb.value		<< endl <<
	"paira.compareTo(pairb): " << paira.compareTo(pairb)	<< endl <<
	"pairb.compareTo(paira): " << pairb.compareTo(paira)	<< endl <<
	"KVP<int,int>(5,3).compareTo(KVP<int,int>(5,6)): " << KVP<int,int>(5,3).compareTo(KVP<int,int>(5,6)) << endl;
	
	using namespace Node;
	
	SLN<int> slna=SLN<int>(2);
	SLN<int> slnb=SLN<int>(&slna,1);
	SLN<int> slnc=SLN<int>(&slnb,0);
	
	slna.appendSucc(slnc.spliceSucc());
	
	//C->A->B
	
	cout <<
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
	
	cout <<
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
	
	//Test 'Number'
	
	Number num=Number(10);
	
	cout << "num.value: " << num.value << endl;
	
	num.value=5;
	
	cout << "num.value: " << num.value << endl;
	
	//Test 'Jump'
	
	InstructionTemp<ADD,Number> itemp=InstructionTemp<ADD,Number>();
	Jump jumpa=Jump();
	Jump jumpb=Jump(&itemp);
	
	cout << "&itemp: " << &itemp << endl;
	cout << "jumpa.target: " << jumpa.target << endl;
	cout << "jumpb.target: " << jumpb.target << endl;
	
	//Test 'Axes'
	
	Axes fiftytwo=Axes(52);
	Axes one=Axes(1);
	long* tofree;
	
	cout << "*(fiftytwo.find(51)): " << *(tofree=fiftytwo.find(51)) << endl;
	delete tofree;
	cout << "fiftytwo.find(52): " << fiftytwo.find(52) << endl;
	
	cout << "*(one.find(0)): " << *(tofree=one.find(0)) << endl;
	delete tofree;
	cout << "one.find(1): " << one.find(1) << endl;
	
	fiftytwo.set(51,8);
	cout << "*(fiftytwo.find(51)): " << *(tofree=fiftytwo.find(51)) << endl;
	delete tofree;
	
	fiftytwo.set(52,3);
	cout << "*(fiftytwo.find(52)): " << *(tofree=fiftytwo.find(52)) << endl;
	delete tofree;
	
	fiftytwo.set(KVP<unsigned long,long>(52,4));
	cout << "*(fiftytwo.find(52)): " << *(tofree=fiftytwo.find(52)) << endl;
	delete tofree;
	
	one.purge();
	cout << "one.getSize(): " << one.getSize() << endl;
	
	fiftytwo.transfer(&one);
	cout <<
	"one.getSize(): " << one.getSize() << endl <<
	"fiftytwo.getSize(): " << fiftytwo.getSize() << endl <<
	"*(one.find(50)): " << *(tofree=one.find(50)) << endl;
	delete tofree;
	cout << "*(one.find(51)): " << *(tofree=one.find(51)) << endl;
	delete tofree;
	cout << "*(one.find(52)): " << *(tofree=one.find(52)) << endl;
	delete tofree;
	
	one.projection(&fiftytwo);
	cout << "one.getSize():" << one.getSize() << endl <<
	"fiftytwo.getSize():" << fiftytwo.getSize() << endl;
	
	one.purge();
	fiftytwo.purge();
	one.set(0,28);
	one.projection(&fiftytwo);
	cout <<
	"one.getSize():" << one.getSize() << endl <<
	"fiftytwo.getSize():" << fiftytwo.getSize() << endl <<
	"*(one.find(0)):" << *(tofree=one.find(0)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(0)):" << *(tofree=fiftytwo.find(0)) << endl;
	delete tofree;
	
	one.purge();
	fiftytwo.purge();
	one.set(3,3);
	one.set(2,2);
	one.set(4,4);
	fiftytwo.set(1,1);
	fiftytwo.set(5,5);
	fiftytwo.set(2,-2);
	fiftytwo.set(4,-4);
	one.biprojection(&fiftytwo);
	
	cout << "*(one.find(1)):" << *(tofree=one.find(1)) << endl;
	delete tofree;
	cout << "*(one.find(2)):" << *(tofree=one.find(2)) << endl;
	delete tofree;
	cout << "*(one.find(3)):" << *(tofree=one.find(3)) << endl;
	delete tofree;
	cout << "*(one.find(4)):" << *(tofree=one.find(4)) << endl;
	delete tofree;
	cout << "*(one.find(5)):" << *(tofree=one.find(5)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(1)):" << *(tofree=fiftytwo.find(1)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(2)):" << *(tofree=fiftytwo.find(2)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(3)):" << *(tofree=fiftytwo.find(3)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(4)):" << *(tofree=fiftytwo.find(4)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(5)):" << *(tofree=fiftytwo.find(5)) << endl;
	delete tofree;
	
	Axes* dolly=fiftytwo.clone();
	cout <<
	"one.compareTo(dolly):" << one.compareTo(dolly) << endl <<
	"one==*dolly:" << (one==*dolly?"true":"false") << endl <<
	"one!=*dolly:" << (one!=*dolly?"true":"false") << endl <<
	"one<*dolly:" << (one<*dolly?"true":"false") << endl <<
	"one<=*dolly:" << (one<=*dolly?"true":"false") << endl <<
	"one>*dolly:" << (one>*dolly?"true":"false") << endl <<
	"one>=*dolly:" << (one>=*dolly?"true":"false") << endl;
	
	fiftytwo+=one;
	*dolly-=one;
	cout << "*(fiftytwo.find(1)):" << *(tofree=fiftytwo.find(1)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(2)):" << *(tofree=fiftytwo.find(2)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(3)):" << *(tofree=fiftytwo.find(3)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(4)):" << *(tofree=fiftytwo.find(4)) << endl;
	delete tofree;
	cout << "*(fiftytwo.find(5)):" << *(tofree=fiftytwo.find(5)) << endl;
	delete tofree;
	cout << "*(dolly->find(1)):" << *(tofree=dolly->find(1)) << endl;
	delete tofree;
	cout << "*(dolly->find(2)):" << *(tofree=dolly->find(2)) << endl;
	delete tofree;
	cout << "*(dolly->find(3)):" << *(tofree=dolly->find(3)) << endl;
	delete tofree;
	cout << "*(dolly->find(4)):" << *(tofree=dolly->find(4)) << endl;
	delete tofree;
	cout << "*(dolly->find(5)):" << *(tofree=dolly->find(5)) << endl;
	delete tofree;
	
	delete dolly;
	
	//Cell c=Cell();
	
	//TODO: Test 'Cell' class here
	
	return 0;
}
