#pragma once
#include <iostream>
#include <string>
#include <vector>

#define PAIR(x,y) std::make_pair<>(x,y)
namespace plt_shared
{


	std::vector<std::string> split_string(const std::string &orgin, char delim = ' ');
}
