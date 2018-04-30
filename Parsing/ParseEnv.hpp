#ifndef PARSEENV_HPP
#define PARSEENV_HPP

namespace Parsing{
	using namespace ExecBlocks;
	using namespace Linear;
	using namespace Details;
	class ParseEnv{
		private:
		Tube<tzj*>	jstack;//Along with this
		tzj		*foreresolve=NULL;
		void resolve(Instruction* totarget);
		public:
		Tube<Instruction*>	chain;
		Tube<Axes*>		vectors;
		Tube<Number*>		numbers;
		Instruction		*next=NULL;
		ParseEnv& jpush();
		ParseEnv& jpop();
		ParseEnv& append(Instruction* toappend);
		~ParseEnv();
	};
}

#endif //PARSEENV_HPP
