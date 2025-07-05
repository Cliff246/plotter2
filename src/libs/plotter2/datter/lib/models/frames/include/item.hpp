#pragma once

#include <map>
#include <cstdint>
#include <set>
#include <memory>


#include "dataholder.hpp"

namespace datter
{
	const int64_t ownedby_proccess = 1;
	const int64_t ownedby_no_one = -1;
	
	class item 
	{
	private:
		
		int64_t m_frameid = -1;
		//THE LOCK you need this to edit the content without just copying
		int64_t m_lockkey = -1; 
				
		//who own's this
		int64_t m_ownedby = ownedby_no_one; 
		int64_t m_orgin = 0;
	
		std::map<std::string, datter::datahold_ptr> m_items;
		std::set<std::string> m_exposed;
		
		


	public:
		item();
		//Change the lock of this
		bool change_lock(int64_t lockkey, int64_t keyset);
		//Simple get lock
		int64_t get_lock() const;

		
		//copies deep to a new lock key
		//TODO
		std::unique_ptr<item> copy_item(int64_t lockkey);
			
		
		
	};
}
