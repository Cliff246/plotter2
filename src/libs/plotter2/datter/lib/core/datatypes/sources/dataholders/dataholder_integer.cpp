
#include "dataholders/dataholder_integer.hpp"



using namespace datter;
using namespace datter::dataholder;


std::string datahold_integer::get_type() const
{
	return integer_type;
}


std::vector<string_pair> datahold_integer::get_args_info() const 
{
	return {
		
	};
}

size_t datahold_integer::get_nargs()
{
	return 0;
}	

