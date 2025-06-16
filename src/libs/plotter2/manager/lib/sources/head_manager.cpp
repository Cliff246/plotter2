#include "file_manager.hpp"
#include "head_manager.hpp"



plt_manager::headmanager::headmanager(size_t maxsize, size_t maxlimit)
{
	m_activesize = maxsize;
	m_activelimit = maxlimit;
}



void plt_manager::headmanager::push_new_task(plt_manager::path_fs path)
{
	std::string name = path.filename(); 
	manager_ptr mang = std::make_shared<plt_manager::manager>(name, path);
	
	m_managers.push_back(mang);
	m_currently.push(mang);
}
