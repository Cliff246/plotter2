#pragma once

#include <mach/port.h>
#include <memory>
#include <vector>

#include "plot.hpp"

#include "node.hpp"
#include "pipeline_template.hpp"

namespace plt_pipeline
{


	
	class pipeline
	{
	private:
		//the template this pipeline uses
		std::shared_ptr<pipeline_template> m_template; 
		//the plot being acted on(later to be deterimined)
		std::shared_ptr<plt_shared::plot> m_plot;
	public:
		pipeline(std::shared_ptr<plt_shared::plot> plot);
		~pipeline();	




	};
}
