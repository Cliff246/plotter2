#include "child.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

using namespace messenger;

sockchild::sockchild()
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
