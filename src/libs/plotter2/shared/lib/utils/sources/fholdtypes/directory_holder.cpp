
#include "fhold.hpp"
#include "fholdtypes/directory_holder.hpp"

bool plt_shared::directory_holder::can_open()
{
	return false;
}

plt_shared::filetype plt_shared::directory_holder::get_fholdtype()
{
	return plt_shared::filetype::directory;
}

bool plt_shared::directory_holder::does_exist() const
{
	return std::filesystem::exists(m_path);	
}


bool plt_shared::directory_holder::can_cache()
{
	return false;
}

plt_shared::fhold_ptr plt_shared::directory_holder::get_holder(const std::string &key)
{
	return m_map[key];
}
		
std::set<std::string> plt_shared::directory_holder::get_keys()
{
	//sketchy 
	std::set<std::string> keys;
	for(const auto &pair : m_map)
	{
		keys.insert(pair.first);
	}
	return keys;	
}
std::set<plt_shared::fhold_ptr> plt_shared::directory_holder::get_values()
{
	std::set<plt_shared::fhold_ptr> values;
	for(const auto &pair : m_map)
	{
		values.insert(pair.second);
	}
	return values;
}

