
#include "manager.hpp"
#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <memory>
#include <stdexcept>

plt_manager::manager::manager(const std::string &name, path_fs path)
{
	const path_fs manfiest_path =  	path.append("manifest.json");

	if(!std::filesystem::exists(manfiest_path))
	{
		throw std::runtime_error("cannot set a path that does not contain a manifest"); 
	}
	m_manifest = std::make_shared<plt_manager::manifest>(manfiest_path);
	m_directory = std::make_shared<plt_manager::directory_manager>(path);	
			
}

plt_manager::manager::~manager()
{

}

std::string &plt_manager::manager::get_manager_name()
{
	return m_manager_name;
}



std::shared_ptr<plt_manager::manifest> plt_manager::manager::get_manifest()
{
	return m_manifest;
}	
		

