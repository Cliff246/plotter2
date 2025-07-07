#pragma once


#include <vector>
#include <string>


#include "orchestration.hpp"
#include "parent.hpp"
#include "childholder.hpp"

namespace p2exe
{
	




	class runtime
	{
	private:
		int arg_count;
		std::vector<std::string> m_arguments;
		//here cause I don't have anything better
		char **m_external;
		orchestrator m_orchestrator;
		


	public:
		runtime(int argv, char **argc, char **external);
		void init();
		void update();
		~runtime();
		void shutdown();
		void eshutdown();


	};

}
