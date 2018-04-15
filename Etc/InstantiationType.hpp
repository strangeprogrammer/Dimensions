#ifndef INSTANTIATIONTYPE_HPP
#define INSTANTIATIONTYPE_HPP

class abstract{
	public:
	virtual void dummy()=0;
	virtual ~abstract(){}
};
#define ABSTRACT virtual private abstract

class concrete:ABSTRACT{
	public:
	void dummy(){}
	virtual ~concrete(){}
};
#define CONCRETE virtual private concrete

#endif //INSTANTIATIONTYPE_HPP
