#include "utils.hpp"
#include "utils_tests.hpp"
#include <string>
#include <vector>
#include <array>
using namespace plt_shared;

TEST(utils_tests, string_split_test)
{
	const std::array<std::string, 4> tokens = {
		"a",
		"b",
		"c",
		"d"
	};
	std::vector<std::string> split = split_string("a b c d");
	
	EXPECT_EQ(split.size(), tokens.size());

	for(int i = 0; i < split.size(); ++i)
	{
	
		EXPECT_EQ(split[i], tokens[i]);
	}	
}	



TEST(utils_tests, string_split_test2)
{
	const std::array<std::string, 1> tokens = {
		"abcd",
	};
	std::vector<std::string> split = split_string("abcd");
	
	EXPECT_EQ(split.size(), tokens.size());

	for(int i = 0; i < split.size(); ++i)
	{
	
		EXPECT_EQ(split[i], tokens[i]);
	}
}


TEST(utils_tests, string_split_test3)
{
	const std::array<std::string, 4> tokens = {
		"a", 
		"b",
		"c",
		"d",
	};
	std::vector<std::string> split = split_string("a b c d   ");
	
	EXPECT_EQ(split.size(), tokens.size());

	for(int i = 0; i < split.size(); ++i)
	{
	
		EXPECT_EQ(split[i], tokens[i]);
	}
}



TEST(utils_tests, string_split_test4)
{
	const std::array<std::string, 9> tokens = {
		"the",
		"little",
		"brown",
		"fox",
		"jumps",
		"over",
		"the",
		"slow",
		"turtle."
	};
	std::vector<std::string> split = split_string("the little brown fox jumps over the slow turtle.");
	
	EXPECT_EQ(split.size(), tokens.size());

	for(int i = 0; i < split.size(); ++i)
	{
	
		EXPECT_EQ(split[i], tokens[i]);
	}
}



TEST(utils_tests, string_split_test5)
{
	const std::array<std::string, 9> tokens = {
		"a",
		"b",
		"c",
		"d",
		"e",
		"f",
		"g",
		"h",
		"i"
	};
	std::vector<std::string> split = split_string("a   b c d             e f   g   h i  ");
	
	EXPECT_EQ(split.size(), tokens.size());

	for(int i = 0; i < split.size(); ++i)
	{
	
		EXPECT_EQ(split[i], tokens[i]);
	}
}
