#include "worker.hpp"
#include <mutex>
#include <thread>
#include <iostream>
#include <unistd.h>

#include <pybind11/embed.h>
namespace py = pybind11;



using namespace p2child;


worker::worker()
{
	
}

//start up worker
void worker::initialize()
{


	m_running = true;
	std::cerr << "aquire\n";
	py::gil_scoped_acquire acquire;	
	std::cerr << "after aquire\n";
	updater();
}

//run worker
void worker::updater()
{
	int count = 0;
	while(m_running)
	{
  		//std::cerr << "before py::print" << std::endl;
        py::exec(R"(print("Hello, World!")

		)");    
        //std::cerr << "after py::print" << std::endl;
        //std::cerr << "running" << "count: " << count++ << std::endl;
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

