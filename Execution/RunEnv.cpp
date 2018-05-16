#include "all.hpp"

using namespace Details;
using namespace ExecBlocks;
using namespace Linear;

RunEnv::RunEnv(Instruction* start,Instruction* current,Storage* s,Axes* position,Axes* velocity):
	start(start),
	current(current),
	s(s),
	position(position),
	velocity(velocity){}

RunEnv::RunEnv(Instruction* start):RunEnv(start,start,new List<>){}

RunEnv::~RunEnv(){
	start=NULL;
}

//Destructor zeroes all variables
