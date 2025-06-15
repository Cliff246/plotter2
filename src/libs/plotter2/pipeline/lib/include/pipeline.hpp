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
		std::vector<std::unique_ptr<plt_pipeline::layer>> m_layers;
		std::shared_ptr<plt_shared::plot> m_plot;
		
	public:
		pipeline(std::shared_ptr<plt_shared::plot> plot);
		~pipeline();	

		void add_layer(layer &layer);
	};
}
