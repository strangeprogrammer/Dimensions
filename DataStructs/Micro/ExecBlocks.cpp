#include "all.hpp"

namespace ExecBlocks{
	using namespace Node;
	
	#define BASE Instruction
	
	#define IT InstructionType
	#define SUPER DLN<IT>
	#define SUPERC SUPER::DLN
	BASE* BASE::spliceSucc(){
		return (BASE*)(SUPER::spliceSucc());
	}
	
	void BASE::appendSucc(BASE* toappend){
		SUPER::appendSucc(toappend);
		return;
	}
	
	BASE::BASE(BASE* prev,BASE* succ,IT it):SUPERC(prev,succ,it){}
	BASE::BASE(BASE* succ,IT it):		SUPERC(succ,it){}
	BASE::BASE(IT it):			SUPERC(it){}
	
	BASE::~BASE(){}
	#undef SUPERC
	#undef SUPER
	#undef IT
	
	using namespace Details;
	
	#define BASET InstructionTemp
	
	//Original code from here on fully mashed into preprocessor directives :)
	#define VANILLA(name,type)\
	name::name():BASE::BASE(type){}\
	name::~name(){}
	
	#define CHOCOLATE(name,type,ctype,carg,dtype)\
	name::name(ctype carg):BASET<type,dtype>::BASET(){this->d=new dtype(carg);}\
	/*Make sure to only pass values allocated from the heap to this*/\
	name::name(dtype* d):BASET<type,dtype>::BASET(){this->d=d;}\
	name::name():BASET<type,dtype>::BASET(){this->d=new dtype();}\
	name::~name(){delete this->d;}
	
	#define AXESCONF(name,type) CHOCOLATE(name,type,long,cartesian,Axes)
	#define NUMBERCONF(name,type) CHOCOLATE(name,type,long,value,Number)
	#define JUMPCONF(name,type) CHOCOLATE(name,type,BASE*,target,Jump)
	
	AXESCONF(mov,MOV);
	AXESCONF(setv,SETV);
	AXESCONF(strv,STRV);
	
	NUMBERCONF(add,ADD);
	NUMBERCONF(sub,SUB);
	
	VANILLA(getc,GETC);
	VANILLA(putn,PUTN);
	VANILLA(putc,PUTC);
	VANILLA(noop,NOOP);
	VANILLA(halt,HALT);
	
	JUMPCONF(tzj,TZJ);
	JUMPCONF(jmp,JMP);
	
	#undef JUMPCONF
	#undef NUMBERCONF
	#undef AXESCONF
	
	#undef CHOCOLATE
	#undef VANILLA
	
	#undef BASET
	#undef BASE
}
