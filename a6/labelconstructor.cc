#include "main.ih"

labelledInt(int someInt, string label);
:
	IntValue(someInt),
	d_label(someInt)
{
}
