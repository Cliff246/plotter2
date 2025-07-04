#pragma once

#include <map>
#include <cstdint>
#include <memory>

#include "dataholder.hpp"

namespace datter
{
	
	const int64_t ownedby_proccess = 1;
	const int64_t ownedby_no_one = -1;
	
	class item 
	{
	private:
		
		int64_t m_frameid;
		int64_t m_lockkey; 

		
				
		//who own's this
		int64_t m_ownedby = ownedby_no_one; 
		
		
		std::map<std::string, datter::datahold_ptr> item;


	public:
		
	};
}
