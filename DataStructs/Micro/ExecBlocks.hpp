#ifndef EXECBLOCKS_HPP
#define EXECBLOCKS_HPP

//If you think this code is really squashed down into preprocessor, just wait until you see what I can REALLY do...
namespace ExecBlocks{
	using namespace Node;
	using namespace Details;
	
	#define BASE Instruction
	#define BASET InstructionTemp
	
	#define SUPERC BASE::BASE
	#define SUPERDEST BASE::~BASE
	template <InstructionType IT,typename D> class BASET:ABSTRACT,public BASE{
		public:
		D* d;
		
		BASET(BASE* prev,BASE* succ):	SUPERC(prev,succ,IT){}
		BASET(BASE* succ):		SUPERC(succ,IT){}
		BASET():			SUPERC(IT){}
		
		virtual ~BASET(){}
	};
	#undef SUPERDEST
	#undef SUPERC
	
	//Original code from here on fully mashed into preprocessor directives :)
	#define VANILLA(name,type)\
	class name:CONCRETE,public BASE{\
		public:\
		name():BASE::BASE(type){}\
		~name(){}\
	}
	#define CHOCOLATE(name,type,ctype,carg,dtype)\
	class name:CONCRETE,public BASET<type,dtype>{\
		public:\
		name(ctype carg):BASET<type,dtype>::BASET(){this->d=new dtype(carg);}\
		/*Make sure to only pass values allocated from the heap to this*/\
		name(dtype* d):BASET<type,dtype>::BASET(){this->d=d;}\
		name():BASET<type,dtype>::BASET(){this->d=new dtype();}\
		~name(){delete this->d;}\
	}
	
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

#endif //EXECBLOCKS_HPP
