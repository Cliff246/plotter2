#pragma once
#include <string>
#include <vector>
#include "plot.hpp"

namespace plt_manager
{
	class manager 
	{
	private:	

		std::string manager_name;
		
		std::vector<plt_shared::plot> plots_involved;
		

		
			
	public:
		manager();
		~manager();

		std::string &get_manager_name();
		
		

	};
}
