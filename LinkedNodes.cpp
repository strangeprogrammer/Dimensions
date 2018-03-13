#include "headers.h"

using namespace std;

//Singly-Linked Node
template <typename T> class SLN{
	public:
	SLN<T>* next;
	T datum;
	
	void appendNext(SLN<T>* toappend){
		DIENULLVOID(toappend);
		toappend->next=next;
		next=toappend;
		return;
	}
	
	SLN<T>* spliceNext(){
		SLN<T>* tosplice=next;
		if(tosplice){
			next=tosplice->next;
		}
		return tosplice;
	}
	
	SLN():next(NULL);
	SLN(T datum):SLN(),datum(datum);
	SLN(SLN<T>* next,T datum):next(next),datum(datum);
	
	~SLN():SLN();
};

//Doubly-Linked Node
template <typename T> class DLN:public SLN<T>{
	public:
	DLN<T>* prev;
	
	void appendNext(DLN<T>* toappend){
		DIENULLVOID(toappend);
		SLN<T>::appendNext(toappend);
		toappend->prev=this;
		if(toappend->next){
			toappend->next->prev=toappend;
		}
		return;
	}
	
	DLN<T>* spliceNext(){
		DLN<T>* tosplice=next;
		if(tosplice){
			next=tosplice->next;
			if(tosplice->next){
				tosplice->next->prev=this;
			}
		}
		return tosplice;
	}
	
	DLN():SLN(),prev(NULL);
	DLN(T datum):SLN(datum),DLN();
	DLN(DLN<T>* next,T datum):SLN(next,datum),DLN();
	DLN(DLN<T>* prev,DLN<T>* next,T datum):SLN(next,datum),prev(prev);
	
	~DLN():~SLN(),prev(NULL);
};

enum InstructionType{
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

class Instruction:public DLN<InstructionType>{
	public:
	Details d;
	
	Instruction():DLN();
	Instruction(InstructionType t):DLN(t);
	Instruction(Instruction next,InstructionType t):DLN(next,t);
	Instruction(Instruction prev,Instruction next,InstructionType t):DLN(prev,next,t);
	
	~Instruction():~DLN();
};

class mov:public Instruction{
	public:
	mov():d(new axes()),Instruction(MOV);
	mov(Instruction next):d(new axes()),Instruction(next,MOV);
	mov(Instruction prev,Instruction next):d(new axes()),Instruction(prev,next,MOV);
	
	~mov():~Instruction(){
		delete d;
		return;
	}
};

class setv:public Instruction{
	public:
	setv():d(new axes()),Instruction(SETV);
	setv(Instruction next):d(new axes()),Instruction(next,SETV);
	setv(Instruction prev,Instruction next):d(new axes()),Instruction(prev,next,SETV);
	
	~setv():~Instruction(){
		delete d;
		return;
	}
};

class add:public Instruction{
	public:
	add():d(new number()),Instruction(ADD);
	add(Instruction next):d(new number()),Instruction(next,ADD);
	add(Instruction prev,Instruction next):d(new number()),Instruction(prev,next,ADD);
	
	~add():~Instruction(){
		delete d;
		return;
	}
};

class sub:public Instruction{
	public:
	sub():d(new number()),Instruction(SUB);
	sub(Instruction next):d(new number()),Instruction(next,SUB);
	sub(Instruction prev,Instruction next):d(new number()),Instruction(prev,next,SUB);
	
	~sub():~Instruction(){
		delete d;
		return;
	}
};

class strv:public Instruction{
	public:
	strv():d(new axes()),Instruction(STRV);
	strv(Instruction next):d(new axes()),Instruction(next,STRV);
	strv(Instruction prev,Instruction next):d(new axes()),Instruction(prev,next,STRV);
	
	~strv():~Instruction(){
		delete d;
		return;
	}
};

class getc:public Instruction{
	public:
	getc():Instruction(GETC);
	getc(Instruction next):Instruction(next,GETC);
	getc(Instruction prev,Instruction next):Instruction(prev,next,GETC);
	
	~getc():~Instruction();
};

class putn:public Instruction{
	public:
	putn():Instruction(PUTN);
	putn(Instruction next):Instruction(next,PUTN);
	putn(Instruction prev,Instruction next):Instruction(prev,next,PUTN);
	
	~putn():~Instruction();
};

class putc:public Instruction{
	public:
	putc():Instruction(PUTC);
	putc(Instruction next):Instruction(next,PUTC);
	putc(Instruction prev,Instruction next):Instruction(prev,next,PUTC);
	
	~putc():~Instruction();
};

class lodv:public Instruction{
	public:
	lodv():Instruction(LODV);
	lodv(Instruction next):Instruction(next,LODV);
	lodv(Instruction prev,Instruction next):Instruction(prev,next,LODV);
	
	~lodv():~Instruction();
};

class tjz:public Instruction{
	public:
	tjz():d(new jump()),Instruction(TJZ);
	tjz(Instruction next):d(new jump()),Instruction(next,TJZ);
	tjz(Instruction prev,Instruction next):d(new jump()),Instruction(prev,next,TJZ);
	
	~tjz():~Instruction(){
		delete d;
		return;
	}
};

class jmp:public Instruction{
	public:
	jmp():d(new jump()),Instruction(JMP);
	jmp(Instruction next):d(new jump()),Instruction(next,JMP);
	jmp(Instruction prev,Instruction next):d(new jump()),Instruction(prev,next,JMP);
	
	~jmp():~Instruction(){
		delete d;
		return;
	}
};

class nop:public Instruction{
	public:
	nop():Instruction(NOP);
	nop(Instruction next):Instruction(next,NOP);
	nop(Instruction prev,Instruction next):Instruction(prev,next,NOP);
	
	~nop():~Instruction();
};

class halt:public Instruction{
	public:
	halt():Instruction(HALT);
	halt(Instruction next):Instruction(next,HALT);
	halt(Instruction prev,Instruction next):Instruction(prev,next,HALT);
	
	~halt():~Instruction();
};
