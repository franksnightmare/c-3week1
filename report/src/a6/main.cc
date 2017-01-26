#include "main.ih"

int main(int argc, char **argv)
{
	IntValue iv(12);
	DoubleValue dv(3.14);
	LabelledInt li(3, "lithium");
	
	cout << iv << '\n';
	cout << dv << '\n';
	cout << li << '\n';
}
