#ifndef DETAILS_HPP
#define DETAILS_HPP

namespace Details{
	class DetailsBase:ABSTRACT{};
	
	#define V long
	#define K unsigned long
	#define SUPER Linear::List<K,V>
	#define SUPERC SUPER::List
	class Axes:CONCRETE,public DetailsBase,public SUPER{
		public:
		//Deletes the old version or makes a new one if it doesn't exist
		void set(K key,V value){
			remove(key);
			insert(key,value);
			return;
		}
		
		void init(unsigned int numaxes){
			for(unsigned long i=0;i<numaxes;i++){
				set(i,0);
			}
			return;
		}
		
		Axes(unsigned int numaxes):SUPERC(){
			init(numaxes);
			return;
		}
		
		Axes():Axes(0){}
		
		~Axes(){}
	};
	#undef SUPERC
	#undef SUPER
	#undef K
	#undef V
	
	class Number:CONCRETE,public DetailsBase{
		public:
		long value;
		
		Number(long value):value(value){}
		Number():value(0){}
		
		~Number(){
			value=0;
			return;
		}
	};
	
	using namespace ExecBlocks;
	
	class Jump:CONCRETE,public DetailsBase{
		public:
		Instruction* target;
		
		Jump(Instruction* target):target(target){}
		Jump():target(NULL){}
		
		~Jump(){
			target=NULL;
			return;
		}
	};
}

#endif //DETAILS_HPP
