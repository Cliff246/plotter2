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
	//update();

}

//SHOULD be our main runtime 
void runtime::update()
{
	for(int i = 0; i < 5; ++i)
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
	exit(1);
}
