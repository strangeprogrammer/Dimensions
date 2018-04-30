#include "all.hpp"

namespace Parsing{
	using namespace ExecBlocks;
	using namespace Linear;
	void ParseEnv::resolve(Instruction* totarget){
		if(foreresolve){
			foreresolve->d->target=totarget;
			foreresolve=NULL;
		}
		return;
	}
	
	ParseEnv& ParseEnv::jpush(){
		jstack.frontpush((tzj*)(chain.backpeek()));
		return *this;
	}
	
	ParseEnv& ParseEnv::jpop(){
		jmp* backresolve=(jmp*)chain.backpeek();
		foreresolve=jstack.frontpop();
		backresolve->d->target=foreresolve;
		return *this;
	}
	
	ParseEnv& ParseEnv::append(Instruction* toappend){
		if(chain.getSize()){
			chain.backpeek()->appendSucc(toappend);
		}
		chain.backpush(toappend);
		resolve(toappend);
		return *this;
	}
	
	ParseEnv::~ParseEnv(){
		while(jstack.getSize()){
			jstack.frontpop();
		}
		while(chain.getSize()){
			delete chain.frontpop();
		}
		while(vectors.getSize()){
			delete vectors.frontpop();
		}
		while(numbers.getSize()){
			delete numbers.frontpop();
		}
		if(next){
			delete next;
		}
	}
}
