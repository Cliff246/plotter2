#pragma once

#include <map>
#include <vector>

#include "dataholder.hpp"
#include "dataitem.hpp"

namespace datter
{
	class dataframe
	{
	private:
		std::vector<dataitem> m_frameitems;
		//points to frame item postions.
		std::map<std::string, size_t> m_framekeys;
		int m_frameid;

	public:

	};
}
