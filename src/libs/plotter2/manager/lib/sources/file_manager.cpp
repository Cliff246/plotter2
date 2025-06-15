#include "file_manager.hpp"

//file holderv
	
//check directory if it exists 
bool plt_manager::directory_manager::does_exist() const
{
	return std::filesystem::exists(m_path);	
}

//test file holder if exists



//directory manager
plt_manager::directory_manager::directory_manager(path_fs &path)
{
	m_path = path; 
}


