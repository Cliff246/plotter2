#pragma once
#include "message.hpp"
#include "socketer.hpp"
#include <array>
#include <queue>
#include <string>
#include <memory>

namespace messenger
{
	//opposite of sockchild
	class childholder
	{
	private:
		std::string m_socket;
		int m_socket_code = -1;
		

		//buffer for reading into
		static const size_t m_buffer_size = BUFFER_SIZE;
		std::array<char, m_buffer_size> m_buffer;
		size_t m_buffer_scroll;		
		

		//should be about the same	
		std::queue<message_ptr> m_message_queue;
		message_ptr m_transit_message;
		
		//the overflow of the buffer;
		std::vector<char> m_buffer_overflow;

	public:

		childholder(const std::string &socket_path);


		//delete it
		~childholder();

		//get the socket path
		std::string get_socket_path() const;


		//get the socket code
		int get_socket_code() const;


		//set socket path for a child
		void set_socket_path(const std::string& socket_path);	
		//the socket code.... don't use?
		void set_socket_code(int socket_code);
		//starts a socket and gives you back the code
		int start_socket();
		//close the socket
		void close_socket();
	};

	using childholder_ptr = std::shared_ptr<childholder>;	
}
