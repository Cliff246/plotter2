#include "parent.hpp"
#include "process.hpp"
#include "childholder.hpp"
#include <cstdint>
#include <map>
#include <memory>
#include <sys/socket.h>
#include <vector>
#include "orchestration.hpp"

using namespace p2exe;

orchestrator::orchestrator()
{

}

void orchestrator::new_proccess(char **env)
{
	std::unique_ptr<process> pro = std::make_unique<process>(env);
	pro->start_up();
	m_processes.push_back(std::move(pro));	
}

//refreshes everything
void orchestrator::refresh()
{
	for(const auto &proc : m_processes)
	{
		proc->check_in();
	}
}

//hard kill all
void orchestrator::kill_all()
{
	for(const auto &proc : m_processes)
	{
		proc->kill_it();	
	}
}

//clean kill all
void orchestrator::close_all()
{
	for(const auto &proc : m_processes)
	{
		proc->shutdown();	
	}
}	

