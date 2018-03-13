#include "headers.h"

class Details;

template<int num> class axes:public Details{
	public:
	axes<num-1> next;
	int polarization:2=0;
	const bool flag:1=1;
};

template<> class axes<0>:public Details{
	public:
	const bool flag:1=0;
	int :0;
};

class number:public Details{
	public:
	long number=0;
};

class jump:public Details{
	public:
	Instruction* target;
};
