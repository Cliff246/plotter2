#pragma once
#include "datasrc.hpp"
#include <memory>
#include <vector>

namespace plt_shared
{
	using datasrc_ptr = std::shared_ptr<datasrc>;
	class datter 
	{
	private:
		std::vector<datasrc_ptr> m_sources;
		
		int m_datter_id;

	public:
		

		datter();

	};
}


