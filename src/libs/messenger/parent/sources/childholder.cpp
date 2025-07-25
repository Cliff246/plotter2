#include "childholder.hpp"
#include "socketer.hpp"
#include <string>

using namespace messenger;

childholder::childholder(const std::string &socket_path)
{
	m_socket = socket_path;

	size_t current = socket_path.find_first_of("0123456789");
	int last = socket_path.size();

	std::string substring = socket_path.substr(current);	
	m_socket_code = std::stoi(substring);
}

childholder::~childholder()
{

}

int childholder::get_socket_code() const
{
	return m_socket_code;
}

std::string childholder::get_socket_path() const
{
	return m_socket;
}

//don't use
void childholder::set_socket_code(int socket_code)
{
	m_socket_code = socket_code;
}

//don't use
void childholder::set_socket_path(const std::string& socket_path)
{
	m_socket = socket_path;
}	


int childholder::start_socket()
{
	if(m_socket_code == -1)
		return -1;
	m_socket_code =	create_a_socket(m_socket.c_str());
	return 0;
}

