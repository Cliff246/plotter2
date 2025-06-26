#include <iostream>
#include "utils_tests.hpp"

int32_t main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();			
}
