#pragma once

#include <atomic>
#include <cstdint>
#include <string>
#include <unistd.h>
#include <vector>
#include "childholder.hpp"

namespace p2exe
{
	//id_counter is 
	extern std::atomic<int64_t> id_counter; 
	class process
	{
	private:
		pid_t m_pid;
		int m_pipe[2];
		//-1 is uninitialized
		int m_id = -1;

		
		
		//pipe buffers
		std::string read_buffer;
		std::string write_buffer;
		//is stalled 	
		uint64_t m_timeup;
		uint64_t m_heartbeat_counter;
		
		bool is_stalled;
		
		messenger::childholder m_socketholder;		
		
	public:
		process();


		void start_up();
			
	};
}
