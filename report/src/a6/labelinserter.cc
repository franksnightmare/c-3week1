#include "main.ih"

ostream &LabelledInt::insertInto(ostream &out)
{
	return out << d_label << ": " << value();
}
