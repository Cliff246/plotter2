#pragma once
#include <string>
#include <vector>

namespace plt_shared
{

	extern std::vector<std::string> get_open_processes();

	extern std::string get_proccess_name(const std::string &ps_format,const std::string &ps_str);
}
