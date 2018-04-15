#ifndef INSTRUCTIONTYPE_HPP
#define INSTRUCTIONTYPE_HPP

enum InstructionType:char{
	MOV,		//Move
	SETV,		//Set Velocity
	ADD,		//Add
	SUB,		//Subtract
	STRV,		//Store Velocity
	GETC,		//Get Character
	PUTN,		//Put Number
	PUTC,		//Put Character
	TZJ,		//Test for 0 and Jump
	JMP,		//Jump Unconditionally
	NOOP,		//No Operation
	HALT		//Halt
};

#endif //INSTRUCTIONTYPE_HPP
