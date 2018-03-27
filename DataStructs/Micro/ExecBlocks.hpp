#include "all.hpp"

namespace ExecBlocks{
	#define PROTO(x) class x:public Instruction{\
		public:\
		x();\
		x(Instruction next);\
		x(Instruction prev,Instruction next);\
		\
		~x();\
	}
	
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
	#undef PROTO_V
}
