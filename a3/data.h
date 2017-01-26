#ifndef DATA_H
#define DTA_H

#include <vector>
#include <memory>
#include <iostream>

class Data
{
	typedef std::vector<std::shared_ptr<std::string>> DataVector;
	
	DataVector d_data;
	
	public:
		typedef std::string value_type;
		void push_back(std::string const &str);
		void vecOutput();
};

#endif
