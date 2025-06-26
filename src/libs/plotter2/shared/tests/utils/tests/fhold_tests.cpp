#include "utils_tests.hpp"
#include "fhold_tests.hpp"

using namespace plt_shared;

TEST(utils_tests, fhold_basics ) {

	path_fs fs("resources/txt.txt");

	file_holder *holder = new file_holder(fs);	
	holder->open_file(std::ios::in);
	for(int i = 0; i < 10; i++)
	{
		char c = holder->read();
		EXPECT_EQ(c, ('0' + i)); 

	}

	delete holder;
}
