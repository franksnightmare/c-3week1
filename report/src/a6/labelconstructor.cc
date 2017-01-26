#include "main.ih"

LabelledInt::LabelledInt(int someInt, string label)
:
	IntValue(someInt),
	d_label(label)
{
}
