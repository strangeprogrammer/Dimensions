#include "all.hpp"

using namespace Details;

//Private functions

void Cell::fromvel(){
	if(type==AXES){
		delete this->velocity;
	}
}

void Cell::testType(types type){
	if(this->type!=type){
		throw 1;
	}
}

//Public functions

void Cell::setc(char c){
	fromvel();
	this->c=c;
	this->type=CHAR;
}

void Cell::setn(long number){
	fromvel();
	this->number=number;
	this->type=LONG;
}

void Cell::setv(Axes* velocity){
	fromvel();
	this->velocity=velocity->clone();
	this->type=AXES;
}

char Cell::getc(){
	testType(types::CHAR);
	return this->c;
}

long Cell::getn(){
	testType(types::LONG);
	return this->number;
}

Axes* Cell::getv(){
	testType(types::AXES);
	return this->velocity->clone();
}

Cell::Cell(char c):c(c),type(CHAR){}
Cell::Cell(long number):number(number),type(LONG){}
Cell::Cell(Axes* velocity):velocity(velocity),type(AXES){}
Cell::Cell():Cell('\0'){}

Cell::~Cell(){
	fromvel();
}
