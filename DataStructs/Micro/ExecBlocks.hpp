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
	
	using namespace Globals;
	
	//Original code from here on fully mashed into preprocessor directives :)
	#define CONSTTEMP(name,cargs,type,dtype,dargs)\
		public:\
		name(cargs):BASET<type,dtype>::BASET(){this->d=new dtype(dargs);}\
		~name(){delete this->d;}
	
	//Maybe change this next line so that the default number of dimensions can be changed
	#define AXESCONF(name,type) CONSTTEMP(name,,type,Axes,dimensions)
	#define NUMBERCONF(name,type) CONSTTEMP(name,long value,type,Number,value)
	#define JUMPCONF(name,type) CONSTTEMP(name,BASE* target,type,Jump,target)
	
	#define VANILLA(name,type) class name:CONCRETE,public BASE{}
	#define CHOCOLATE(name,type,dtype,config) class name:CONCRETE,public BASET<type,dtype>{config(name,type)}
	
	#define AXOID(name,type) CHOCOLATE(name,type,Axes,AXESCONF)
	#define NUMOID(name,type) CHOCOLATE(name,type,Number,NUMBERCONF)
	#define JUMPOID(name,type) CHOCOLATE(name,type,Jump,JUMPCONF)
	
	AXOID(mov,MOV);
	AXOID(setv,SETV);
	AXOID(strv,STRV);
	
	NUMOID(add,ADD);
	NUMOID(sub,SUB);
	
	VANILLA(getc,GETC);
	VANILLA(putn,PUTN);
	VANILLA(putc,PUTC);
	VANILLA(lodv,LODV);
	VANILLA(noop,NOOP);
	VANILLA(halt,HALT);
	
	JUMPOID(tzj,TZJ);
	JUMPOID(jmp,JMP);
	
	#undef AXOID
	#undef NUMOID
	#undef JUMPOID
	
	#undef CLASSCONF
	#undef VANILLA
	
	#undef JUMPCONF
	#undef NUMBERCONF
	#undef AXESCONF
	
	#undef CONSTTEMP
	
	#undef BASET
	#undef BASE
}
