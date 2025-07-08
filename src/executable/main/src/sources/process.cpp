#include <algorithm>
#include <signal.h>
#include <cstdint>
#include <atomic>
#include <memory>
#include <unistd.h>

#include <spawn.h>
#include <sys/wait.h>
#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <vector>
#include "loggy.hpp"
#include "parent.hpp"
#include "childholder.hpp"
#include "process.hpp"

using namespace p2exe;


std::atomic<int64_t> p2exe::id_counter = 0; 


p2exe::process::process(char **environ)
{
	std::string path = messenger::generate_socket_path(id_counter);	
	
	m_socketholder = std::make_shared<messenger::childholder>(path); 
	m_timeup = 0;



}


int process::start_up()
{
	plt_shared::logg("startup");    
	if (pipe(m_pipe_in) == -1) 
	{
		plt_shared::logg("could not create pipe in");
		return -1;
	}

	if (pipe(m_pipe_out) == -1) 
	{
		plt_shared::logg("could not create pipe out");
		return -1;
	}

	//if (pipe(m_pipe_err) == -1) 
	//{
	//	plt_shared::logg("could not create pipe err");
	//	return -1;
	//}
	plt_shared::logg("pipes done");
    posix_spawn_file_actions_init(&m_actions);

	//argv
	// Example for stdin
	posix_spawn_file_actions_adddup2(&m_actions, m_pipe_in[0], STDIN_FILENO);
	posix_spawn_file_actions_addclose(&m_actions, m_pipe_in[1]);

	// Example for stdout
	posix_spawn_file_actions_adddup2(&m_actions, m_pipe_out[1], STDOUT_FILENO);
	posix_spawn_file_actions_addclose(&m_actions, m_pipe_out[0]);

	// Example for stderr
	//posix_spawn_file_actions_adddup2(&m_actions, m_pipe_err[1], STDERR_FILENO);
	//posix_spawn_file_actions_addclose(&m_actions, m_pipe_err[0]);	
	m_socketholder->set_socket_code(id_counter++);
	std::string socket_path = m_socketholder->get_socket_path();
	plt_shared::logg("binded");
    char *argv[] = {
		const_cast<char *>("./child"),
		const_cast<char *>(socket_path.c_str()),
	   	nullptr
	};


    if (posix_spawn(&m_pid, "./child", &m_actions, nullptr, argv, m_environment) != 0) 
	{

		
		
		plt_shared::logg("could not spawn" );
        return -1;
    }
	int flags = fcntl(m_pipe_out[0], F_GETFL, 0);
	fcntl(m_pipe_out[0], F_SETFL, flags | O_NONBLOCK);
	plt_shared::logg("spawned");

	m_queue_in.push("Hello from parent\n");
	m_queue_in.push("Second message\n");
	m_queue_in.push("test test test\n");
	   	 
	m_queue_in.push("exit\n");
	
	if(m_socketholder->start_socket() == -1)
	{
		//shittttt
		writeto("exit");
		plt_shared::logg(plt_shared::ERROR, "could not start socket");

		is_open = false;		
		return -1;
	}
	plt_shared::logg(plt_shared::LOG, "started socket");
	is_open = true;
	return 0;
}


void process::check_in()
{
	
    // Parent process: close read end, write messages
	if(!is_open)    
		return;
	const int size = 1000;
	if(m_queue_in.size() != 0)
	{
		const std::string msg = m_queue_in.front();
		m_queue_in.pop();
		write(m_pipe_in[1], msg.c_str(), msg.size());

	}
	
			
	char buffer[size] = {0};
	ssize_t n  = 0;	

	int available = 0;
	std::vector<std::string> output;
	while ((n = read(m_pipe_out[0], buffer, size - 1)) > 0 || available > 0) 
	{
 		buffer[n] = '\0';
		int remaining = n;
		int current = 0;
		while(current < n)
		{
			std::string copy; 
			copy.reserve(n);
			for(int i = current; i < n; ++i, ++current)
			{
				if(buffer[i] == '\n')
					break;
				copy += buffer[i];
			}
			current++;
			output.push_back(copy);
		}
		//std::cout << '\n';

		ioctl(m_pipe_out[0], FIONREAD, &available);
			//plt_shared::logg(plt_shared::LOG, "child:  %s\n", buffer);
	}

	for(const auto &chout : output)
	{
		plt_shared::logg(plt_shared::LOG, "child:  %s", chout.c_str());

	}	
				
		//for(int i = 0; i < size; ++i)
		//{
		//	if(buffer[i] == '\0')
		//	{

		//	}	
		//}	
	



}


int process::writeto(const std::string &str)
{
	if(is_open)
	{
		const std::string msg = m_queue_in.front();
		m_queue_in.pop();
		write(m_pipe_in[1], msg.c_str(), msg.size());
		return 0;
	}
	else
		return -1;
}

//default shut down
//TODO
void process::shutdown()
{
	is_open = false;		
	writeto("exit");
	//close it ALL
    close(m_pipe_in[0]);
    close(m_pipe_in[1]);
    close(m_pipe_out[0]);
    close(m_pipe_out[1]);
    close(m_pipe_err[0]);
    close(m_pipe_err[1]);
}

//should be only used in emergencies or unresponsive
void process::killit()
{
	
	kill(m_pid, SIGKILL);	
	close(m_pipe_in[0]);
    close(m_pipe_in[1]);
    close(m_pipe_out[0]);
    close(m_pipe_out[1]);
    close(m_pipe_err[0]);
    close(m_pipe_err[1]);

	is_open = false;		
}


