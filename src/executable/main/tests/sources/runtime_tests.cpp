#include "runtime_tests.hpp"

using namespace p2exe;


//starts up rt
void runtime_tests::SetUp() 
{
	const int arg_count = 1;
	char *argc[arg_count] = {
		(char *)"./p2main_tests"
	};
	char **args = &argc[0];

	//init runtime
	rt = new runtime(arg_count + 1, argc, nullptr);



}

void runtime_tests::TearDown()
{
	if(rt != nullptr)
	{
		//delete it;
		delete rt;
	}
}
