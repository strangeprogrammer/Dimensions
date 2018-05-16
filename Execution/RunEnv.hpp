#ifndef RUNENV_HPP
#define RUNENV_HPP

using namespace Details;
using namespace ExecBlocks;

class RunEnv{
	private:
	bool owngen;
	public:
	Instruction		*start,
				*current;
	Storage<Axes*,Cell*>	*s;
	Axes			*position,
				*velocity;
	
	RunEnv(Instruction* start,Instruction* current,Storage<Axes*,Cell*>* s,Axes* position,Axes* velocity);
	RunEnv(Instruction* start);
	//Constructor sets 'start' and 's' to given values and zeroes position and velocity
	
	~RunEnv();
	//Destructor zeroes all variables
};

#endif //RUNENV_HPP
