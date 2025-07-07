#pragma once

#include <atomic>
#include <cstdint>
#include <string>
#include <unistd.h>
#include <spawn.h>
#include <vector>
#include <queue>
#include "childholder.hpp"

namespace p2exe
{
	//id_counter is 
	extern std::atomic<int64_t> id_counter; 
	class process
	{
	private:
		pid_t m_pid;
		int m_pipe_out[2];
		int m_pipe_in[2];
		int m_pipe_err[2];
		//-1 is uninitialized
		int m_id = -1;
		
		
		std::queue<std::string> m_queue_in;		

    	posix_spawn_file_actions_t m_actions;
		
		//pipe buffers
		std::string m_read_buffer;
		std::string m_write_buffer;
		//is stalled 	
		uint64_t m_timeup;
		uint64_t m_heartbeat_counter;
		//test for that
		bool is_stalled;
		bool is_open;
		messenger::childholder_ptr m_socketholder;		
		

		//memeory map shit
		char *m_read_memmap = nullptr;
		char *m_write_memmap = nullptr;
		char **m_environment;

		int writeto(const std::string &str);

	public:
		process(char **environ);


		int start_up();
		void check_in();
		void shutdown();
		void killit();
	};
}
