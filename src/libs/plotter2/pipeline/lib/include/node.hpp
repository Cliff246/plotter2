#pragma once
#include <memory>
#include <vector>
#include "layer.hpp"

namespace plt_pipeline
{
	using edgeary = std::vector<int>;	
	class node
	{
	private:
		edgeary m_edges;
		layer_ptr m_layer;
		std::vector<std::string> m_depends; 


	public:
		node();
		~node();	
	};
	using node_ptr = std::unique_ptr<node>;

}
