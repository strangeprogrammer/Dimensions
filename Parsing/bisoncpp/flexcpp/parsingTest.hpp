#ifndef PARSINGTEST_H
#define PARSINGTEST_H

enum Parser{
	LPAREN	=1,
	RPAREN	=2,
	MFORE	=3,
	MBACK	=4,
	VSTORE	=5,
	VFORE	=6,
	VBACK	=7,
	VZERO	=8,
	PLUS	=9,
	MINUS	=10,
	INASCII	=11,
	OUTNUM	=12,
	OUTASCII=13,
	WHILE	=14,
	ENDWHILE=15,
	NOOP	=16,
	NUMBER	=17,
	LETTER	=18
};

#endif //PARSINGTEST_H