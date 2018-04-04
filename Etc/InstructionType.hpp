#ifndef INSTRUCTIONTYPE_H
#define INSTRUCTIONTYPE_H

enum InstructionType:char{
	UNUSED=0,	//Unused
	MOV,		//Move
	SETV,		//Set Velocity
	ADD,		//Add
	SUB,		//Subtract
	STRV,		//Store Velocity
	GETC,		//Get Character
	PUTN,		//Put Number
	PUTC,		//Put Character
	LODV,		//Load Velocity
	TZJ,		//Test and Jump on 0
	JMP,		//Unconditional Jump
	NOP,		//No Operation
	HALT		//Halt
};

#endif //INSTRUCTIONTYPE_H
