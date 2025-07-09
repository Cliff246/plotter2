#include "utils_tests.hpp"
#include "process_inspector_tests.hpp"

using namespace plt_shared;


TEST(utils_tests, proccess_test ) 
{
	for(const auto &i : get_open_proccesses())
	{
		//std::cerr << i << "\n";
	}
	

}
