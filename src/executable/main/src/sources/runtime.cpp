#include <exception>
#include <unistd.h>



#include <spawn.h>
#include <sys/wait.h>
#include <iostream>

#include "runtime.hpp"
#include "loggy.hpp"
using namespace p2exe;


//honestly just a wraper for argv, argc and env
runtime::runtime(int argv, char **argc, char **external)
{
	arg_count = argv;
	m_external = external;	
	//push new string
	for(int i = 0; i < argv; ++i)
	{
		std::string copy(argc[i]);
		m_arguments.push_back(copy);
	}
}

//should init all
//TODO
void runtime::init()
{
	plt_shared::logg("logging this");
	m_orchestrator.new_proccess(m_external);	
	m_orchestrator.new_proccess(m_external);	
	m_running = true;
	runner();
	//update();

}



//this is the runner and should attempt to recover or clean shutdown at all costs 
void runtime::runner()
{
	try
	{
		update();
	}



	catch(const std::exception &except1)
	{



		std::cerr << "error down to runner: " << except1.what() << "\n";
		//csd = clean shutdown
		//esd = emergency shutdown
		const int csd = -1, esd = -2; 
		//clean shutdown
		try
		{
			//please die
			shutdown();
			exit(csd);
		}
		//very hard shutdown
		catch(const std::exception &except2)
		{
			
			std::cerr << "serius shutdown failure hard exit:" << except2.what() << "\n";
			//die die die
			eshutdown();
			abort();
		}
	}

}




//SHOULD be our main runtime 
void runtime::update()
{
	while(m_running == true)
	{
		sleep(1);
		m_orchestrator.refresh();

	}

}


runtime::~runtime()
{
	shutdown();
}


//shut down cleanly
//TODO
void runtime::shutdown()
{
	plt_shared::logg(plt_shared::ERROR, "shutdown all");
	m_orchestrator.close_all();
	exit(0);
}

//shut down hard
//TODO
void runtime::eshutdown()
{
	plt_shared::logg(plt_shared::ERROR, "killing all");
	m_orchestrator.kill_all();
	abort();
}
