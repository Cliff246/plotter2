#include "message.hpp"
#include "parent.hpp"
using namespace messenger; 

const std::string messenger::generate_socket_path(int code)
{

	const std::string default_path( socket_path); 

	std::string buffer = default_path + std::to_string(code) + ".sock";
	return buffer;

}


parent_messenger::parent_messenger()
{

}

parent_messenger::~parent_messenger()
{

}



std::vector<childholder_ptr> parent_messenger::get_children() const
{
	return m_children;
}



size_t parent_messenger::get_number_children() const
{

	return m_children.size();
}



