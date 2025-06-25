#pragma once

#include <mach/port.h>
#include <memory>
#include <vector>
#include "layer.hpp"

#include "plot.hpp"

#include "node.hpp"

namespace plt_pipeline
{


	
	class pipeline
	{
	private:
		std::vector<node_ptr> m_nodes;
		int start = -1;
		int stop = -1;	
		//start node & end
		//plot running on
		std::shared_ptr<plt_shared::plot> m_plot;
		

	public:
		pipeline(std::shared_ptr<plt_shared::plot> plot);
		~pipeline();	




	};
}
