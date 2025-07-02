

#pragma once

#include <mach/port.h>
#include <map>
#include <memory>
#include <vector>

#include "plot.hpp"

#include "node.hpp"

namespace plt_pipeline
{


	
	class pipeline_template
	{
	private:
		

		std::vector<node_ptr> m_pipeline;

			

	public:

		
	
		pipeline_template();
	   	~pipeline_template();
		
		//check if all ready 
		bool all_ready() const;	
		
			
		//get the pipeline
		std::vector<node_ptr> get_pipeline() const;
		//get the node at the pipeline index
		node_ptr get_pipeline_index(int index) const;		


	};
}
