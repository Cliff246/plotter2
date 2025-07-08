#include <iostream>
#include "loggy.hpp"
#include <gtest/gtest.h>


int32_t main(int argc, char **argv) 
{
	plt_shared::init_loggy();
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();			
}
