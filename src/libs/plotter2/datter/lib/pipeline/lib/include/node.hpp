#pragma once
#include <memory>
#include <vector>
#include "layer.hpp"

namespace plt_pipeline
{
	class node
	{
	private:
		std::shared_ptr<layer> m_layer;	
		bool isloaded;	
	public:
		node();
		~node();	
	};
	using node_ptr = std::unique_ptr<node>;

}
