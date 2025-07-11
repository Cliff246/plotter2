#pragma once
#include <locale>
#include <memory>
#include <queue>
#include <string>
#include <array>
#include "message.hpp" 

namespace messenger 
{
	class sockchild
	{
	private:
		int m_socket;
		std::string m_path;
		//buffer size
		const static size_t m_buffer_size = 2048;
		//buffer
		std::array<char, m_buffer_size> m_buffer;
		//current scroll head. 
		int m_buffer_scroll = 0;
		//message queue
		std::queue<message_ptr> m_message;
		message_ptr m_transit_message;
		//weird function but it fixes a 
		void conjoin_data_and_add(std::string extra);

	public:
		//
		sockchild();	
		~sockchild();
		//start up
		void init(std::string &path);


		//refresh will read the socket
		void refresh();
		int set_up_socket();
		message read_message();	
	};
}
