#pragma once

#include <memory>
#include "bundle_container.hpp"

#include "task.hpp"
#include "frame.hpp"


//this is going to be really hard 

namespace datter
{
	//core bundle in memory class
	//this bad boy stores containers, tasks alot
	//use this bad boy to make a frame
	class bundle
	{
	private:
		std::unique_ptr<bundle_container> m_container;
		
		bool m_instanced;

	public:
		//makes frame from bundle
		std::unique_ptr<frame> convert_to_frame();		
	};
}
