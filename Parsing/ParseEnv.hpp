#ifndef PARSEENV_HPP
#define PARSEENV_HPP

namespace Parsing{
	using namespace ExecBlocks;
	using namespace Linear;
	using namespace std;
	class ParseEnv{
		private:
		Tube<Instruction*>	chain;
		Tube<tzj*>		jstack;
		tzj			*foreresolve=NULL;
		
		void resolve(Instruction* totarget){
			if(foreresolve){
				foreresolve->d->target=totarget;
				foreresolve=NULL;
			}
			return;
		}
		
		public:
		ParseEnv& jpush(){
			jstack.frontpush((tzj*)(chain.backpeek()));
			return *this;
		}
		
		ParseEnv& jpop(){
			jmp* backresolve=(jmp*)chain.backpeek();
			foreresolve=jstack.frontpop();
			backresolve->d->target=foreresolve;
			return *this;
		}
		
		ParseEnv& append(Instruction* toappend){
			if(chain.getSize()){
				chain.backpeek()->appendSucc(toappend);
			}
			chain.backpush(toappend);
			resolve(toappend);
			return *this;
		}
		
		Instruction* package(){
			append(new halt());
			return chain.frontpeek();
		}
		
	};
}

#endif //PARSEENV_HPP
