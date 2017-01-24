#include "main.ih"

ostream &DoubleValue::insertInto(ostream &out)
{
	return out << d_double;
}
