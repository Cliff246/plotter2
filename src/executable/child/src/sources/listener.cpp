
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include "listener.hpp"


using namespace p2child;



listener::listener(int argc, char **argv)
{
	for(int i = 0; i < argc; ++i)
	{
		if(argv[i] != nullptr)
		{
			std::string newarg(argv[i]); 
			m_arguments.push_back(newarg);
		}
	}



	m_worker = std::make_unique<worker>();
	
	
}



void listener::start()
{
	m_worker->start();
	m_running = true;
		
}


void listener::update()
{
	std::string buf;
	while(m_running)
	{
		if(!std::getline(std::cin, buf))
		{
			m_running = false;
			continue;
		}
		std::cout << buf << '\n';
		
	}	
	m_worker->join();
	std::cout << "dying\n";
}

