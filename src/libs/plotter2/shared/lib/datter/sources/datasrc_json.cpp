#include "datasrc_json.hpp"
#include <stdexcept>


using namespace plt_shared;

datasrc_json::datasrc_json()
{

}

datasrc_json::~datasrc_json()
{

}


std::string datasrc_json::get_type() const
{


	return "json";
}
bool datasrc_json::set_file(path_fs &path)
{
	m_holder = std::make_shared<file_holder>(path);	
	if(m_holder->can_open() && m_holder->does_exist())
	{
		loaded = true;
		return true;
	}
	loaded = false;
	return false;
}

std::vector<std::vector<datahold_ptr>> get_data()
{
	//TODO
	throw std::runtime_error("unimplemented");
}	


