
#include "dataholders/dataholder_integer.hpp"



using namespace plt_shared::dataholder;


std::string datahold_integer::get_type() const
{
	return plt_shared::integer_type;
}


std::vector<plt_shared::string_pair> datahold_integer::get_args_info() const 
{
	return {
		
	};
}

size_t datahold_integer::get_nargs()
{
	return 0;
}	

