#ifndef NODE_HPP
#define NODE_HPP

//Please don't mix the node types here
namespace Node{
	template <typename T,typename N> class SLNBase:ABSTRACT{
		public:
		N* succ;
		T datum;
		
		SLNBase(N* succ,T datum):	succ(succ){
			this->datum=datum;
		}
		SLNBase(T datum):		SLNBase(NULL,datum){}
		SLNBase():			succ(NULL){}
		
		virtual ~SLNBase(){succ=NULL;}
	};
	
	//Singly-Linked Node
	//'N' should be a subclass of 'SLN'
	#define SUPER SLNBase<T,SLN<T>>
	#define SUPERC SUPER::SLNBase
	template <typename T> class SLN:CONCRETE,public SUPER{
		public:
		using SUPER::succ;
		using SUPER::datum;
		
		virtual SLN<T>* appendSucc(SLN<T>* toappend){
			DIENULL(toappend);
			toappend->succ=succ;
			succ=toappend;
			return toappend;
		}
		
		virtual SLN<T>* spliceSucc(){
			SLN<T>* tosplice=succ;
			if(tosplice){
				succ=tosplice->succ;
			}
			return tosplice;
		}
		
		SLN(SLN<T>* succ,T datum):	SUPERC(succ,datum){}
		SLN(T datum):			SUPERC(datum){}
		SLN():				SUPERC(){}
		
		virtual ~SLN(){}
	};
	#undef SUPERC
	#undef SUPER
	
	#define SUPER SLNBase<T,N>
	#define SUPERC SUPER::SLNBase
	template <typename T,typename N> class DLNBase:ABSTRACT,public SUPER{
		public:
		N* prev;
		
		DLNBase(N* prev,N* succ,T datum):	SUPERC(succ,datum),prev(prev){}
		DLNBase(N* succ,T datum):		DLNBase(NULL,succ,datum){}
		DLNBase(T datum):			DLNBase(NULL,NULL,datum){}
		DLNBase():				SUPERC(),prev(NULL){}
		
		virtual ~DLNBase(){prev=NULL;}
	};
	#undef SUPERC
	#undef SUPER
	
	//Doubly-Linked Node
	#define SUPER DLNBase<T,DLN<T>>
	#define SUPERC SUPER::DLNBase
	template <typename T> class DLN:CONCRETE,public SUPER{
		public:
		using SUPER::succ;
		using SUPER::datum;
		using SUPER::prev;
		
		virtual DLN<T>* appendSucc(DLN<T>* toappend){
			DIENULL(toappend);
			toappend->succ=succ;
			succ=toappend;
			toappend->prev=this;
			if(toappend->succ){
				toappend->succ->prev=toappend;
			}
			return toappend;
		}
		
		virtual DLN<T>* spliceSucc(){
			DLN<T>* tosplice=succ;
			if(tosplice){
				succ=tosplice->succ;
				if(tosplice->succ){
					tosplice->succ->prev=this;
				}
			}
			return tosplice;
		}
		
		DLN(DLN<T>* prev,DLN<T>* succ,T datum):	SUPERC(prev,succ,datum){}
		DLN(DLN<T>* succ,T datum):		SUPERC(succ,datum){}
		DLN(T datum):				SUPERC(datum){}
		DLN():					SUPERC(){}
		
		virtual ~DLN(){}
	};
	#undef SUPERC
	#undef SUPER
}

#endif //NODE_HPP
