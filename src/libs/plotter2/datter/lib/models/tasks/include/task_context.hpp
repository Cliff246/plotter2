#pragma once

#include <cstdint>
#include <memory>
#include "frame.hpp"

namespace datter
{


	//datter's task context system
	//this is the scope of a task 
	//held uniquely by a task. not THE ACTUAL FRAME that's to say
	//just a temporary task work space
	//
	class task_context
	{
	private:
		uint64_t m_context_id;
		std::unique_ptr<datter::frame> m_frame; 
		
		
	public:
			
	};
}
