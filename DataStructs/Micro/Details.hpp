#include "all.hpp"

namespace Details{
	template <int num> class axes:public Basis{//TODO: Replace this with a 'Linear::Linear' structure
		public:
		axes<num-1> next;
		int polarization:2;
		const bool flag:1;
		axes();
	};
	
	template <> class axes<0>:public Basis{//See previous
		public:
		const bool flag:1;
		int :0;
		axes();
	};
	
	class number:public Basis{
		public:
		long number;
	};
	
	using namespace ExecBlocks;
	
	class jump:public Basis{
		public:
		Instruction* target;
	};
}
