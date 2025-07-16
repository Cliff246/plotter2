#pragma once
#include <locale>
#include <memory>
#include <queue>
#include <string>
#include <array>
#include "message.hpp" 

#include "socketer.hpp"
namespace messenger 
{
	//oposite of childholder
	class sockchild
	{
	private:
		//socket info
		int m_socket;
		std::string m_path;
		//buffer size
		const static size_t m_buffer_size = BUFFER_SIZE;
		//buffer
		std::array<char, m_buffer_size> m_buffer;
		//current scroll head. 
		int m_buffer_scroll = 0;
		//message queue into from parent
		std::queue<message_ptr> m_message_in;
		message_ptr m_transit_message_in;

		//message queue out to parent
		std::queue<message_ptr> m_message_out;
		message_ptr m_transit_message_out;

	
		std::vector<char> m_buffer_overflow;

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
