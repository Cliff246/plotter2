#pragma once
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "message.hpp"

namespace messenger
{
	using sockint = int;

	void write_socket(sockint socket, message &msg);
	sockint create_a_socket(const char *path);
}
