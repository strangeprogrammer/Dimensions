#include "all.hpp"

namespace Details{
	#define V long
	#define K unsigned V
	//Deletes the old version of a pair or makes a new one if it doesn't exist
	void Axes::set(K key,V value){
		remove(key);
		insert(key,value);
		return;
	}
	
	void Axes::init(K numaxes){
		for(K i=0;i<numaxes;i++){
			set(i,0);
		}
		return;
	}
	
	Axes::Axes(K numaxes):Linear::List<K,V>::List(){
		init(numaxes);
		return;
	}
	
	Axes::Axes():Axes(0){}
	
	Axes::~Axes(){}
	#undef K
	#undef V
	
	Number::Number(long value):value(value){}
	Number::Number():value(0){}
		
	Number::~Number(){
		value=0;
		return;
	}
	
	Jump::Jump(ExecBlocks::Instruction* target):target(target){}
	Jump::Jump():target(NULL){}
	
	Jump::~Jump(){
		target=NULL;
		return;
	}
}
