#pragma once

#include <thread>
#include <atomic>
#include <mutex>

namespace p2child
{

	enum worker_type
	{
		datter,
		python
	};

	class worker
	{
	private:
		std::thread m_thread;
		//the thread's running
		std::atomic<bool> m_running;
		//worker type
		std::mutex m_type_mutex;
		worker_type m_type;
		

		//initalize on the threads side
		void initialize();
			
		//main run loop
		void updater();

		


	public:
				
		worker();
		//create thread
		void start();
		//join 
		void join();
		//get the worker type
		worker_type get_worker_type();
		

		//stop the thread and push to a new task
		void cease();

		

	};

}
