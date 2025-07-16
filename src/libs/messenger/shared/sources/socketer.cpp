#include "message.hpp"
#include "socketer.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

using namespace messenger;


//static size of all the buffers 

int messenger::create_a_socket(const char *path)
{
	int sock = socket(AF_UNIX, SOCK_STREAM, 0);
	sockaddr_un addr {};
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, path);
	unlink(addr.sun_path); // Remove if it exists
	if(bind(sock, (sockaddr*)&addr, sizeof(addr)) < 0)
	{
		close(sock);
		return -1;
	}
	listen(sock, 1);
	int fd = accept(sock, nullptr, nullptr);
	return fd;
}
