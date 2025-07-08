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
		
		friend class runtime_tests;
		int arg_count;
		std::vector<std::string> m_arguments;
		//here cause I don't have anything better
		char **m_external;
		orchestrator m_orchestrator;
		bool m_running = false;

		void update();
		void set_up_signals();



	public:
		runtime(int argv, char **argc, char **external);
		void init();

		void runner();

		//update funtion
		//destructor invokes normal shutdown
		~runtime();
		//shutdown normally 
		void shutdown();
		//emergency shutdown 
		void eshutdown();


	};

}
