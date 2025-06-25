#pragma once

#include <memory>
#include <vector>
#include "layer.hpp"

#include "plot.hpp"

namespace plt_pipeline
{


	
	
	class pipeline
	{
	private:
		std::vector<layer_ptr> m_nodes;
		std::vector<std::vector<int>> m_edges; 
		int start_node;
		int end_node;
		std::shared_ptr<plt_shared::plot> m_plot;
		
	public:
		pipeline(std::shared_ptr<plt_shared::plot> plot);
		~pipeline();	

		void add_layer(layer *layer);
	};
}
