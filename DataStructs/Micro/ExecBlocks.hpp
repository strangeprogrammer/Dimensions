//If you think this code is really squashed down into preprocessor, just wait until you see what I can REALLY do...
namespace ExecBlocks{
	using namespace Node;
	using namespace Details;
	
	#define DBASE DetailsBase
	#define TBASE InstructionType
	#define BASE Instruction
	#define BASEA InstructionTempA
	
	#define SUPER BASE
	#define SUPERCONST SUPER::SUPER
	#define SUPERDEST SUPER::~SUPER
	//Only use 'D' with objects that inherit from 'DetailsBase'
	template <TBASE IT> class BASEA:public SUPER{
		public:
		DetailsBase* d;
		
		virtual void dummy()=0;
		
		BASEA(BASE* prev,BASE* succ):	SUPERCONST(prev,succ,IT){}
		BASEA(BASE* succ):		SUPERCONST(succ,IT){}
		BASEA():			SUPERCONST(IT){}
		
		virtual ~BASEA(){}
	};
	#undef SUPERDEST
	#undef SUPERCONST
	#undef SUPER
	
	using namespace Globals;
	
	//Original code from here on fully mashed into preprocessor directives :)
	#define CONSTTEMP(name,cargs,type,dtype,dargs)\
		public:\
		name(cargs):SUPER(type)::BASEA(){this->d=new dtype(dargs);}\
		~name(){delete this->d;}
	
	#define AXESCONF(name,type) CONSTTEMP(name,,type,axes,dimensions)
	#define NUMBERCONF(name,type) CONSTTEMP(name,long value,type,number,value)
	#define JUMPCONF(name,type) CONSTTEMP(name,BASE* target,type,jump,target)
	
	#define CLASSIFY(name,type,config) class name: public SUPER(type){config}
	#define CLASSCONF(name,type,config) CLASSIFY(name,type,config(name,type))
	
	#define SUPER(type) BASEA<type>
	
	CLASSCONF(mov,MOV,AXESCONF);
	CLASSCONF(setv,SETV,AXESCONF);
	CLASSCONF(strv,STRV,AXESCONF);
	
	CLASSCONF(add,ADD,NUMBERCONF);
	CLASSCONF(sub,SUB,NUMBERCONF);
	
	CLASSIFY(getc,GETC,);
	CLASSIFY(putn,PUTN,);
	CLASSIFY(putc,PUTC,);
	CLASSIFY(lodv,LODV,);
	CLASSIFY(nop,NOOP,);
	CLASSIFY(halt,HALT,);
	
	CLASSCONF(tzj,TZJ,JUMPCONF);
	CLASSCONF(jmp,JMP,JUMPCONF);
	
	#undef SUPER
	
	#undef CLASSCONF
	#undef CLASSIFY
	
	#undef JUMPCONF
	#undef NUMBERCONF
	#undef AXESCONF
	
	#undef CONSTTEMP
	
	#undef BASEB
	#undef BASEA
	#undef BASE
	#undef TBASE
	#undef DBASE
}
