#ifndef CELL_HPP
#define CELL_HPP

class Cell{
	private:
	union{
		public:
		char c;
		long number;
		Details::Axes* velocity;
	};
	enum types{
		CHAR,
		LONG,
		AXES
	} type;
	void fromvel();
	void testType(types type);
	public:
	void setc(char c);
	void setn(long number);
	void setv(Details::Axes* velocity);
	char getc();
	long getn();
	Details::Axes* getv();
	Cell(char c);
	Cell(long number);
	Cell(Details::Axes* velocity);
	Cell();
	~Cell();
};

#endif //CELL_HPP
