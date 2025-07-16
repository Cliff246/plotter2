#pragma once
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "message.hpp"

namespace messenger
{

	#define BUFFER_SIZE 4096

	int create_a_socket(const char *path);
}
