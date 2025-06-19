#include "dataholders/dataholder_string.hpp"

using namespace plt_shared::dataholder;

std::string datahold_string::get_type() const
{
	return plt_shared::string_type;
}
std::vector<plt_shared::string_pair> datahold_string::get_args_info() const 
{
	return {
		PAIR(plt_shared::integer_type, "length")
	};
}
size_t datahold_string::get_nargs()
{
	return 1;
}	
datahold_string::~datahold_string()
{

}	
std::string datahold_string::get_arg(size_t index)
{
	std::string buf;
	switch(index)
	{
		case 0:
			{

			}
			break;
	}

	return buf;
}	
			
std::string datahold_string::get_string()
{
	return string;
}
void datahold_string::set_string(std::string str)
{
	string = str;
}




