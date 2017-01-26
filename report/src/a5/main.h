#ifndef MAIN_H
#define MAIN_H

#include "inserter.h"

class IntValue : public Inserter<IntValue>
{
	int d_int;
	
	public:
		IntValue(int someInt);
	
	private:
		std::ostream &insertInto(std::ostream &out);
	
	friend Inserter;
};

class DoubleValue : public Inserter<DoubleValue>
{
	double d_double;
	
	public:
		DoubleValue(double someDouble);
	
	private:
		std::ostream &insertInto(std::ostream &out);
	
	friend Inserter;
};

#endif
