#include "child.hpp"
#include <memory>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

using namespace messenger;

sockchild::sockchild()
{
	m_transit_message_in = std::make_unique<message>();
	m_transit_message_out = std::make_unique<message>();
}

sockchild::~sockchild()
{

}

void sockchild::init(std::string &path)
{
	m_socket = -1;
	m_path = path;
}



int sockchild::set_up_socket()
{	
	m_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	struct sockaddr_un addr = {};
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, m_path.c_str());
	int ret = connect(m_socket, (struct sockaddr*)&addr, sizeof(addr));
	if(ret == -1)
		return -1;		
	return ret;
}



void conjoin_data_and_add(std::string extra)
{
	
};
void sockchild::refresh()
{
	ssize_t result = recv(m_socket, m_buffer.data() + m_buffer_scroll, m_buffer.size() - m_buffer_scroll, 0);	
	if(result < 0)
	{

	}
	else if(result == m_buffer_size)
	{
		
	}	
}



message sockchild::read_message()
{
	message current_message;
	return current_message;
}	




