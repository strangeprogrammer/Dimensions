#ifndef LINKED_NODES
#define LINKED_NODES

template <typename T> class SLN;
template <typename T> class DLN:public SLN<T>;
enum InstructionType;
class Instruction:public DLN<InstructionType>;
class mov:public Instruction;
class setv:public Instruction;
class add:public Instruction;
class sub:public Instruction;
class strv:public Instruction;
class getc:public Instruction;
class putn:public Instruction;
class putc:public Instruction;
class lodv:public Instruction;
class tjz:public Instruction;
class jmp:public Instruction;
class nop:public Instruction;
class halt:public Instruction;

#endif /*LINKED_NODES*/
