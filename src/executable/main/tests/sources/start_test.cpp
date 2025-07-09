#include "runtime.hpp"
#include <gtest/gtest.h>
#include <array>

extern char **environ;
using namespace p2exe;




TEST(p2exe_start_test, basic_start) 
{

	//start up runtime
	char *argc[] = {
		"./p2main_tests"
	};
	char **args = &argc[0];

	p2exe::runtime rt = runtime(1, args ,environ);	
	//init runtime
	rt.init();
	rt.shutdown();
}
