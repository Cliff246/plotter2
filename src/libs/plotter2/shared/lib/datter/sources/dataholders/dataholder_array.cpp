
#include "dataholders/dataholder_array.hpp"


using namespace plt_shared::dataholder;


std::string datahold_array::get_type() const
{
	return plt_shared::array_type;
}


std::vector<plt_shared::string_pair> datahold_array::get_args_info() const 
{
	return 
	{
   		PAIR(integer_type, "length"),
	};
}


size_t datahold_array::get_nargs()
{
	return 1;
}	
