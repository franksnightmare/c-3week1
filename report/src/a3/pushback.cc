#include "data.ih"

void Data::push_back(string const &str)
{
	shared_ptr<string> somePtr =
		make_shared<string>(str);
	
	d_data.push_back(somePtr);
}
