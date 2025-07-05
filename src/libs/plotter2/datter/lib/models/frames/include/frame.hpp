#pragma once

#include <map>
#include <memory>
#include <vector>

#include "dataholder.hpp"
#include "item.hpp"

namespace datter
{
	class frame
	{
	private:
		//points to frame item postions.
		std::map<int, std::unique_ptr<item>> m_frame;
	
		std::map<std::string, int> m_exposed;
		
	public:
		frame();
		
		

	};
}
