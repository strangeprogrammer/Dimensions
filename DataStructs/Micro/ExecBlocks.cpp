#include "all.hpp"

namespace ExecBlocks{
	enum InstructionType:char{
		MOV,	//Move
		SETV,	//Set Velocity
		ADD,	//Add
		SUB,	//Subtract
		STRV,	//Store Velocity
		GETC,	//Get Character
		PUTN,	//Put Number
		PUTC,	//Put Character
		LODV,	//Load Velocity
		TZJ,	//Test and Jump on 0
		JMP,	//Unconditional Jump
		NOP,	//No Operation
		HALT	//Halt
	};
	
	using namespace Details;
	using namespace Node;
	
	class Instruction:public DLN<InstructionType>{
		public:
		Basis* d;
		
		Instruction():DLN();
		Instruction(InstructionType t):DLN(t);
		Instruction(Instruction next,InstructionType t):DLN(next,t);
		Instruction(Instruction prev,Instruction next,InstructionType t):DLN(prev,next,t);
		
		~Instruction():~DLN();
	};
	
	#define INSTR(x,y,z) class x:public Instruction{\
		public:\
		x():d(new y()),Instruction(z);\
		x(Instruction next):d(new y()),Instruction(next,z);\
		x(Instruction prev,Instruction next):d(new y()),Instruction(prev,next,z);\
		\
		~x():~Instruction(){\
			delete d;\
			return;\
		}\
	}
	
	#define INSTR_V(x,z) class x:public Instruction{\
		public:\
		x():d(NULL),Instruction(z);\
		x(Instruction next):d(NULL),Instruction(next,z);\
		x(Instruction prev,Instruction next):d(NULL),Instruction(prev,next,z);\
		\
		~x():~Instruction();\
	}
	
	INSTR(mov,axes,MOV);
	INSTR(setv,axes,SETV);
	INSTR(add,number,ADD);
	INSTR(sub,number,SUB);
	INSTR(strv,axes,STRV);
	INSTR_V(getc,GETC);
	INSTR_V(putn,PUTN);
	INSTR_V(putc,PUTC);
	INSTR_V(lodv,LODV);
	INSTR(tjz,jump,TJZ);
	INSTR(jmp,jump,JMP);
	INSTR_V(nop,NOP);
	INSTR_V(halt,HALT);
	
	#undef INSTR
	#undef INSTR_V
}
