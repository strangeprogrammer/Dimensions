#ifndef EXECBLOCKS_HPP
#define EXECBLOCKS_HPP

namespace ExecBlocks{
	using namespace Node;
	using namespace Details;
	
	#define BASE Instruction
	#define BASET InstructionTemp
	
	#define SUPER BASE::BASE
	template <InstructionType IT,typename D> class BASET:ABSTRACT,public BASE{
		public:
		D* d;
		
		BASET(BASE* prev,BASE* succ):	SUPER(prev,succ,IT){}
		BASET(BASE* succ):		SUPER(succ,IT){}
		BASET():			SUPER(IT){}
		
		virtual ~BASET(){}
	};
	#undef SUPER
	
	//Original code from here on fully mashed into preprocessor directives :)
	#define VANILLA(name,type)\
	class name:CONCRETE,public BASE{\
		public:\
		name();\
		~name();\
	}
	#define CHOCOLATE(name,type,ctype,carg,dtype)\
	class name:CONCRETE,public BASET<type,dtype>{\
		public:\
		name(ctype carg);\
		/*Make sure to only pass values allocated from the heap to this*/\
		name(dtype* d);\
		name();\
		~name();\
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
