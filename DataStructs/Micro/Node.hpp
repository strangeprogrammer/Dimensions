namespace Node{
	//Singly-Linked Node
	template <typename T> class SLN{
		public:
		SLN<T>* next;
		T datum;
		
		void appendNext(SLN<T>* toappend);
		SLN<T>* spliceNext();
		
		SLN();
		SLN(T datum);
		SLN(SLN<T>* next,T datum);
		
		~SLN();
	};
	
	//Doubly-Linked Node
	template <typename T> class DLN:public SLN<T>{
		public:
		DLN<T>* prev;
		
		void appendNext(DLN<T>* toappend);
		DLN<T>* spliceNext();
		
		DLN();
		DLN(T datum);
		DLN(DLN<T>* next,T datum);
		DLN(DLN<T>* prev,DLN<T>* next,T datum);
		
		~DLN();
	};
}
