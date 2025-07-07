#include "worker.hpp"
#include <mutex>
#include <thread>
#include <iostream>
#include <unistd.h>
using namespace p2child;


worker::worker()
{

}

//start up worker
void worker::initialize()
{
	
	m_running = true;
	updater();
}

//run worker
void worker::updater()
{
	int count = 0;
	while(m_running)
	{

		std::cout << "running" << "count: " << count++ << "\n";
		sleep(1);
	}	

	std::cout << "thread die\n";
}

//create thread
void worker::start()
{
 	m_thread = std::thread(&worker::initialize, this);

}


//just for shut down
void worker::join()
{
	m_running = false;
	if (m_thread.joinable()) m_thread.join();


}


//safe get worker type
//or to be safe idk
worker_type worker::get_worker_type()
{
	std::lock_guard<std::mutex> lock(m_type_mutex);
	return m_type;
}

