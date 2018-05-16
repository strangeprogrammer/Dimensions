#ifndef DETAILS_HPP
#define DETAILS_HPP

namespace Details{
	class DetailsBase:ABSTRACT{};
	
	//TODO: TEST ALL THE NEW STUFF PUT INTO 'Axes'
	#define U unsigned
	#define SUPER Linear::List<U long,long>
	class Axes:CONCRETE,public DetailsBase,public SUPER{
		public:
		//Deletes the old version of a pair or makes a new one if it doesn't exist
		void set(U long key,long value);
		void set(KVP<U long,long> pair);
		void init(U long numaxes);
		void transfer(Axes* other);
		void projection(Axes* other);
		void biprojection(Axes* other);
		Axes* clone();
		long compareTo(Axes* other);
		bool operator==(Axes& other);
		bool operator!=(Axes& other);
		bool operator<(Axes& other);
		bool operator<=(Axes& other);
		bool operator>(Axes& other);
		bool operator>=(Axes& other);
		Axes& operator+=(Axes& other);
		Axes& operator-=(Axes& other);
		Axes(U long numaxes);
		Axes();
		~Axes();
	};
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
