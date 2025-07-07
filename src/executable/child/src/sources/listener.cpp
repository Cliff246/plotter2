
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
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
	//assumes arg 1 is the socket 
	m_child.init(m_arguments[1]); 	
	//joins socket
	m_child.set_up_socket();
	//starts worker thread
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
			continue;
		}
		if(buf == "exit")
		{
			m_running = false;

			continue;
		}
		std::cout << buf;
	}	
	std::cout << "dying";
	m_worker->join();
}

