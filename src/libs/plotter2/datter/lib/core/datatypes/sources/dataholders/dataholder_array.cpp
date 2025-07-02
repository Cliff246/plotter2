
#include "dataholders/dataholder_array.hpp"

using namespace datter;
using namespace datter::dataholder;


std::string datahold_array::get_type() const
{
	return array_type;
}


std::vector<string_pair> datahold_array::get_args_info() const 
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
