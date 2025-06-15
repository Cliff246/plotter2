
#include "manager.hpp"
#include "iostream"
#include "string"

plt_manager::manager::~manager()
{

}

std::string &plt_manager::manager::get_manager_name()
{
	return manager_name;
}
