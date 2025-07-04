#pragma once

#include <map>
#include <vector>

#include "dataholder.hpp"
#include "item.hpp"

namespace datter
{
	class frame
	{
	private:
		//points to frame item postions.
		std::map<int, item> m_framekeys;
	
		std::map<std::string, int> m_exposed;

	public:

	};
}
