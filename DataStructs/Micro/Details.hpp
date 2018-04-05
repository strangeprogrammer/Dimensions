namespace Details{
	class DetailsBase{
		public:
		virtual ~DetailsBase()=0;
	};
	
	#define V long
	#define K unsigned long
	#define SUPER Linear::LL<K,V>
	#define SUPERCONST SUPER::LL
	class axes:public DetailsBase,public SUPER{
		public:
		//Deletes the old version or makes a new one if it doesn't exist
		void set(K key,V value){
			remove(key);
			insert(key,value);
			return;
		}
		
		//This'll work as long as numaxes!=ULONG_MAX
		void init(unsigned int numaxes){
			for(numaxes++;numaxes;numaxes--){
				insert(numaxes,0);
			}
			return;
		}
		
		axes(unsigned int numaxes):SUPERCONST(){
			init(numaxes);
			return;
		}
		
		axes():SUPERCONST(){}
		
		~axes(){}
	};
	#undef SUPERDEST
	#undef SUPERCONST
	#undef SUPER
	#undef K
	#undef V
	
	class number:public DetailsBase{
		public:
		long value;
		
		number(long value):value(value){}
		number():value(0){}
		
		~number(){
			value=0;
			return;
		}
	};
	
	using namespace ExecBlocks;
	
	class jump:public DetailsBase{
		public:
		Instruction* target;
		
		jump(Instruction* target):target(target){}
		jump():target(NULL){}
		
		~jump(){
			target=NULL;
			return;
		}
	};
}
