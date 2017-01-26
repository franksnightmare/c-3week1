#include "data.ih"

void Data::vecOutput()
{
	for (shared_ptr<string> element : d_data)
		cout << *element << ' ';
	cout << '\n';
}

