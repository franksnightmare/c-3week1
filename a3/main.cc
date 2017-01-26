#include "data.ih"

int main(int argc, char **argv)
{
	Data DataObj;
	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		back_inserter(DataObj));
	DataObj.vecOutput();	
}
