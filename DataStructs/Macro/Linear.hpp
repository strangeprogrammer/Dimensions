namespace Linear{
	template <typename T> class Linear{
		public:
		void frontpush(T datum);
		T frontpop();
		T frontpeek();
		void backpush(T datum);
		T backpop();
		T backpeep();
		//This function serves as an API call, an optimization layer, and an error checking layer on top of 'actualRoll'
		bool roll(long hops);
		unsigned long getSize();
		Linear():crux(new DLN<T>()),elements(0);
		~Linear();
	};
	//TODO: Implement this
	template <typename K,typename V> class LL:public Storage,private Linear;
}
