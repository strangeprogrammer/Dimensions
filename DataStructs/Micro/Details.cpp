#include "all.hpp"

namespace Details{
	template <int num> class axes:public Basis{//TODO: Replace this with a 'Linear::Linear' structure
		public:
		axes<num-1> next;
		int polarization:2=0;
		const bool flag:1;
		axes():flag(1);
	};
	
	template <> class axes<0>:public Basis{//See previous
		public:
		const bool flag:1;
		int :0;
		axes():flag(0);
	};
	
	class number:public Basis{
		public:
		long number=0;
	};
	
	using namespace ExecBlocks;
	
	class jump:public Basis{
		public:
		Instruction* target;
	};
}
