#include "runtime.hpp"


using namespace p2exe;



runtime::runtime(int argv, char **argc)
{
	arg_count = argv;
	
	//push new string
	for(int i = 0; i < argv; ++i)
	{
		std::string copy(argc[i]);
		arguments.push_back(copy);
	}
}


void runtime::update()
{
	
}
