#include "main.ih"

ostream &IntValue::insertInto(ostream &out)
{
	return out << d_int;
}
