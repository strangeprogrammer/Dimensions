#include "all.hpp"

using namespace Linear;
using namespace ExecBlocks;

class RunEnv {
	private:
	Instruction* start;
	Storage* s;
	//Some type of positional construct
	//Some type of velocity contsruct
	
	public:
	long execute(long* retval){
		//let temp equal start
		//do
			//switch on the type of the block in temp
				//case simple movement
					//Modify position
					//break
				//case velocity
					//Modify velocity
					//break
				//case alter cell
					//remove item from storage that has current position as key
					//alter item
					//put item back into storage
					//break
				//case conditional jump
					//if the item found in storage with the current position is non-zero
				//case unconditional jump
					//let temp equal jump destination
					//break
			//let temp equal it's successor
			//update current position with velocity
		//While the instruction's code isn't halt
		//Return the value of the item in storage indexed by current position
	}
	
	//Constructor sets 'start' and 's' to given values and zeroes position and velocity
	
	//Destructor zeroes all variables
};
