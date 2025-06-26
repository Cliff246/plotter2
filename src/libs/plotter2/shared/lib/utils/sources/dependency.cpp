#include "dependency.hpp"
#include "fholdtypes//file_holder.cpp"

#include <set>
using namespace plt_shared;

dependency::dependency(std::string &key)
{
	m_dependency_key = key;
}

dependency::~dependency()
{
	
}	

std::string dependency::get_dependkey() const
{
	return m_dependency_key;
}

fhold_ptr dependency::get_holder() const
{
	return m_holder;
}
		//don't double set
void dependency::set_holder(fhold_ptr hold)
{
	m_holder = hold;
}



bool dependency::is_resolved()
{
	switch(m_holder->get_fholdtype())
	{
		//file type(can resolve)
		case file:
			{
				file_holder	*file = static_cast<file_holder *>(&*m_holder);	
				bool loaded = file->is_loaded();
			}
		//directory type(fails)
		case directory:
			return false;
		default:
			return false;
			
	}

	

	return false;
}

bool dependency::is_ready_instance(std::set<std::string> &set)
{
	if(set.contains(m_dependency_key))
	{
		return is_resolved();
	}	
	else
	{
		set.insert(m_dependency_key);
		for(const auto &depends : m_dependencies)
		{
			bool result = depends->is_ready_instance(set);
			if(result == false)
			{
				return false;
			}
		}
		return true;
	}

}

bool dependency::is_ready()
{
	//TODO
	//this could be circular 

	std::set<std::string> current = {m_dependency_key};	
	return is_ready_instance(current);
}	

