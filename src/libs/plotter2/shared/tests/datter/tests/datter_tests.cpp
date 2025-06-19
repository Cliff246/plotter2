
#include "datter_tests.hpp"


#include <gtest/gtest.h>


int test1()
{
	return 1;
}


TEST(datter_tests, test1) {
	EXPECT_EQ(test1(), 1); 
}
