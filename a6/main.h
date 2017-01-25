#ifndef MAIN_H
#define MAIN_H

#include "inserter.h"

class IntValue : public Inserter<IntValue>
{
	int d_int;
	
	public:
		IntValue(int someInt);
		int value();
	
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

class LabelledInt : public IntValue
{
	std::string d_label;
	
	public:
		labelledInt(int someInt, std::string label);
	
	private:
		std::ostream &insertInto(std::ostream &out);
	
	friend Inserter;
};

#endif
