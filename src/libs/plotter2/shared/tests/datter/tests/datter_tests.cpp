
#include "datter_tests.hpp"



int test1()
{
	return 1;
}






TEST(datter_tests, test1) {
	EXPECT_EQ(test1(), 1); 
}
