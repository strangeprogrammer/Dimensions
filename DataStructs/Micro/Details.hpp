#ifndef DETAILS_HPP
#define DETAILS_HPP

namespace Details{
	class DetailsBase:ABSTRACT{};
	
	#define U unsigned
	#define SUPER Linear::List<U long,long>
	#define SUPERC SUPER::List
	class Axes:CONCRETE,public DetailsBase,public SUPER{
		public:
		//Deletes the old version of a pair or makes a new one if it doesn't exist
		void set(U long key,long value);
		void init(U long numaxes);
		Axes(U long numaxes);
		Axes();
		~Axes();
	};
	#undef SUPERC
	#undef SUPER
	#undef U
	
	class Number:CONCRETE,public DetailsBase{
		public:
		long value;
		Number(long value);
		Number();
		~Number();
	};
	
	using namespace ExecBlocks;
	
	class Jump:CONCRETE,public DetailsBase{
		public:
		Instruction* target;
		Jump(Instruction* target);
		Jump();
		~Jump();
	};
}

#endif //DETAILS_HPP
