#pragma once

#include "dataholder.hpp"
namespace datter
{
	
	const int ownedby_proccess = 1;
	const int ownedby_no_one = -1;
	
	class dataitem 
	{
	private:
		

		
		
		std::unique_ptr<datahold> m_holder;	
		std::shared_ptr<const std::string> m_exportkey;  
		//who own's this
		int m_ownedby = ownedby_no_one; 
		
		



	public:
		
	};
}
