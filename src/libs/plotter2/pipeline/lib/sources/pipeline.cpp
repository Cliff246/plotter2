
#include <memory>
#include <vector>
#include "pipeline.hpp"

#include "plot.hpp"

plt_pipeline::pipeline::pipeline(std::shared_ptr<plt_shared::plot> plot)
{
	m_plot = plot;
}

plt_pipeline::pipeline::~pipeline()
{
	
}


void plt_pipeline::pipeline::add_layer(layer *layer)
{
	m_nodes.push_back(std::make_unique<plt_pipeline::layer*>(layer));	
}
