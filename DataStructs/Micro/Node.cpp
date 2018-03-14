#include "all.hpp"

namespace Node{
	//Singly-Linked Node
	template <typename T> class SLN{
		public:
		SLN<T>* next;
		T datum;
		
		void appendNext(SLN<T>* toappend){
			DIENULLVOID(toappend);
			toappend->next=next;
			next=toappend;
			return;
		}
		
		SLN<T>* spliceNext(){
			SLN<T>* tosplice=next;
			if(tosplice){
				next=tosplice->next;
			}
			return tosplice;
		}
		
		SLN():next(NULL);
		SLN(T datum):SLN(),datum(datum);
		SLN(SLN<T>* next,T datum):next(next),datum(datum);
		
		~SLN():SLN();
	};
	
	//Doubly-Linked Node
	template <typename T> class DLN:public SLN<T>{
		public:
		DLN<T>* prev;
		
		void appendNext(DLN<T>* toappend){
			DIENULLVOID(toappend);
			SLN<T>::appendNext(toappend);
			toappend->prev=this;
			if(toappend->next){
				toappend->next->prev=toappend;
			}
			return;
		}
		
		DLN<T>* spliceNext(){
			DLN<T>* tosplice=next;
			if(tosplice){
				next=tosplice->next;
				if(tosplice->next){
					tosplice->next->prev=this;
				}
			}
			return tosplice;
		}
		
		DLN():SLN(),prev(NULL);
		DLN(T datum):SLN(datum),DLN();
		DLN(DLN<T>* next,T datum):SLN(next,datum),DLN();
		DLN(DLN<T>* prev,DLN<T>* next,T datum):SLN(next,datum),prev(prev);
		
		~DLN():~SLN(),prev(NULL);
	};
}
