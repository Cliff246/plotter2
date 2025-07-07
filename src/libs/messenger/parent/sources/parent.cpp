#include "message.hpp"
#include "parent.hpp"
using namespace messenger; 

const std::string messenger::generate_socket_path(int code)
{

	const std::string default_path( socket_path); 

	std::string buffer = default_path + std::to_string(code) + ".sock";
	return buffer;

}










