#pragma once
#include <memory>
#include <string>
#include <vector>
#include "plot.hpp"
#include "file_manager.hpp"
#include "manifest.hpp"

namespace plt_manager
{
	class manager 
	{
	private:	
		bool valid;
		std::string m_manager_name;
			
		std::shared_ptr<plt_manager::directory_manager> m_directory;	

		std::shared_ptr<plt_manager::manifest> m_manifest;
		
			
	public:
		manager();
		manager(const std::string &name, path_fs path);
		~manager();

		std::string &get_manager_name();
		
		std::shared_ptr<plt_manager::manifest> get_manifest();		
		

	};
}
