#ifndef EXECBLOCKS_HPP
#define EXECBLOCKS_HPP

//If you think this code is really squashed down into preprocessor, just wait until you see what I can REALLY do...
namespace ExecBlocks{
	using namespace Node;
	using namespace Details;
	
	#define SUPER Instruction
	#define SUPERCONST SUPER::SUPER
	#define SUPERDEST SUPER::~SUPER
	//Only use 'D' with objects that inherit from 'DetailsBase'
	template <typename D,InstructionType IT> class InstructionTempA:public SUPER{
		protected:
		virtual void initd(){
			d=new D();
			return;
		}
		
		public:
		DetailsBase* d;
		
		virtual void dummy()=0;
		
		InstructionTempA(Instruction* prev,Instruction* succ):	SUPERCONST(prev,succ,IT){initd();}
		InstructionTempA(Instruction* succ):			SUPERCONST(succ,IT){initd();}
		InstructionTempA():					SUPERCONST(IT){initd();}
		
		virtual ~InstructionTempA(){
			delete d;
			return;
		}
	};
	#undef SUPERDEST
	#undef SUPERCONST
	#undef SUPER
	
	#define SUPER InstructionTempA<DetailsBase,IT>
	#define SUPERCONST SUPER::InstructionTempA
	template <InstructionType IT> class InstructionTempB:public InstructionTempA<DetailsBase,IT>{
		protected:
		virtual void initd(){
			return;
		}
		
		public:
		virtual void dummy()=0;
		
		InstructionTempB(Instruction* prev,Instruction* succ):SUPERCONST(prev,succ){}
		InstructionTempB(Instruction* succ):SUPERCONST(succ){}
		InstructionTempB():SUPERCONST(){}
		
		virtual ~InstructionTempB(){}
	};
	#undef SUPERCONST
	#undef SUPER
	
	using namespace Globals;
	
	#define BASE Instruction
	#define BASEA InstructionTempA
	#define BASEB InstructionTempB
	
	#define SUPER(T) BASEA<axes,T>
	
	#define AXESCONFIG(classname,T)\
		public:classname():SUPER(T)::BASEA(){((axes*)(this->d))->init(dimensions);}
	
	class mov:	public SUPER(MOV)	{AXESCONFIG(mov,MOV)};
	class setv:	public SUPER(SETV)	{AXESCONFIG(setv,SETV)};
	class strv:	public SUPER(STRV)	{AXESCONFIG(strv,STRV)};
	
	#undef AXESCONFIG
	
	#define NUMBERCONFIG(classname,T)\
		public:classname(long num):SUPER(T)::BASEA(){((number*)(this->d))->value=num;}
	
	#undef SUPER
	#define SUPER(T) BASEA<number,T>
	class add:	public SUPER(ADD)	{NUMBERCONFIG(add,ADD)};
	class sub:	public SUPER(SUB)	{NUMBERCONFIG(sub,SUB)};
	
	#undef NUMBERCONFIG
	
	#undef SUPER
	#define SUPER(T) BASEB<T>
	class getc:	public SUPER(GETC)	{};
	class putn:	public SUPER(PUTN)	{};
	class putc:	public SUPER(PUTC)	{};
	class lodv:	public SUPER(LODV)	{};
	class nop:	public SUPER(NOP)	{};
	class halt:	public SUPER(HALT)	{};
	
	#define JUMPCONFIG(classname,T)\
		public:classname(Instruction* target):SUPER(T)::BASEA(){((jump*)(this->d))->target=target;}
	
	#undef SUPER
	#define SUPER(T) BASEA<jump,T>
	class tzj:	public SUPER(TZJ)	{JUMPCONFIG(tzj,TZJ)};
	class jmp:	public SUPER(JMP)	{JUMPCONFIG(jmp,JMP)};
	
	#undef JUMPCONFIG
	
	#undef SUPER
	
	#undef BASEB
	#undef BASEA
	#undef BASE
}

#endif //EXECBLOCKS_HPP
