#pragma once

#include <memory>
#include <string>
#include <vector>
#include "child.hpp"
#include "worker.hpp"

namespace p2child
{
	class listener
	{
	private:
		//messenger child class
		messenger::child m_child;		


		//the worker
		std::unique_ptr<worker> m_worker;
		
		std::vector<std::string> m_arguments;
		bool m_running;

	public:
		// just the start up
		listener(int argc, char **argv);



		void start();
				
		void update();
		
		void shutdown();
		


		
	};
}
