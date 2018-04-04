#ifndef NODE_HPP
#define NODE_HPP

//Please don't mix the node types here
namespace Node{
	//Singly-Linked Node
	template <typename T> class SLN{
		public:
		SLN<T>* succ;
		T datum;
		
		virtual void appendSucc(SLN<T>* toappend){
			DIENULLVOID(toappend);
			toappend->succ=succ;
			succ=toappend;
			return;
		}
		
		virtual SLN<T>* spliceSucc(){
			SLN<T>* tosplice=succ;
			if(tosplice){
				succ=tosplice->succ;
			}
			return tosplice;
		}
		
		SLN(SLN<T>* succ,T datum):	succ(succ),datum(datum){}
		SLN(T datum):			succ(NULL),datum(datum){}
		SLN():				succ(NULL),datum(NULL){}
		
		virtual ~SLN(){
			succ=NULL;
			return;
		}
	};
	
	//Doubly-Linked Node
	#define SUPER SLN<T>
	template <typename T> class DLN:public SUPER{
		#define SUPERCONST SUPER::SLN
		#define SUPERDEST SUPER::~SLN
		public:
		using SUPER::succ;
		using SUPER::datum;
		DLN<T>* prev;
		
		virtual void appendSucc(DLN<T>* toappend){
			DIENULLVOID(toappend);
			SUPER::appendSucc(toappend);
			toappend->prev=this;
			if(toappend->succ){
				((DLN<T>*)(toappend->succ))->prev=toappend;
			}
			return;
		}
		
		virtual DLN<T>* spliceSucc(){
			DLN<T>* tosplice=(DLN<T>*)(succ);
			if(tosplice){
				succ=tosplice->succ;
				if(tosplice->succ){
					((DLN<T>*)(tosplice->succ))->prev=this;
				}
			}
			return tosplice;
		}
		
		DLN(DLN<T>* prev,DLN<T>* succ,T datum):	SUPERCONST(succ,datum),prev(prev){}
		DLN(DLN<T>* succ,T datum):		SUPERCONST(succ,datum),prev(NULL){}
		DLN(T datum):				SUPERCONST(datum),prev(NULL){}
		DLN():					SUPERCONST(),prev(NULL){}
		
		virtual ~DLN(){
			prev=NULL;
		}
		#undef SUPERDEST
		#undef SUPERCONST
	};
	#undef SUPER
}

#endif //NODE_HPP
