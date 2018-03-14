namespace ExecBlocks{
	enum InstructionType;
	class Instruction:public Node::DLN<InstructionType>;
	
	#define PROTO(x) class x:public Instruction
	
	PROTO(mov);
	PROTO(setv);
	PROTO(add);
	PROTO(sub);
	PROTO(strv);
	PROTO(getc);
	PROTO(putn);
	PROTO(putc);
	PROTO(lodv);
	PROTO(tjz);
	PROTO(jmp);
	PROTO(nop);
	PROTO(halt);
	
	#undef PROTO
}
