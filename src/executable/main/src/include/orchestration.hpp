#pragma once

#include "parent.hpp"
#include "process.hpp"
#include "childholder.hpp"
#include <cstdint>
#include <map>
#include <vector>


namespace p2exe
{
	class orchestrator
	{
	private:
		//
		messenger::parent_messenger m_messenger;
		//map of the processes based on id
		std::vector<std::unique_ptr<process>> m_processes;
		//list of the processes 
		//default of 4
		int max_procceses = 4;


	public:

		orchestrator();
		void refresh();
	};
}
