#pragma once

#include <string>

namespace datter
{

	//this should be implemented for each task type
	//THIS IS for:
	//	scripts
	//	pipelines
	//	configurations
	//
	//
	//TODO
	class tasker
	{
	private:
		
	public:

		virtual std::string get_type() = 0;
	};
}
