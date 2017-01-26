#ifndef INSERTER_H
#define INSERTER_H

#include <iostream>

template <typename Derived>
class Inserter
{
	private:
		std::ostream &insertInto(std::ostream &out)
		{
			return static_cast<Derived*>(this)->insertInto(out);
		}
	
	template <typename Derivative>
	friend std::ostream &operator<<(std::ostream &out, Inserter<Derivative> &base);
};

template <typename Derivative>
std::ostream &operator<<(std::ostream &out, Inserter<Derivative> &base)
{
	return base.insertInto(out);
}

#endif
