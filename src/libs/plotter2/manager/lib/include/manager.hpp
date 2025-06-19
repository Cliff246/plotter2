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
		bool m_valid = false;
		std::string m_manager_name;
			
		std::shared_ptr<plt_manager::directory_manager> m_directory;	

		std::shared_ptr<plt_manager::manifest> m_manifest;
		
			
	public:
		manager();
		manager(const std::string &name, path_fs path);
		~manager();

		void set_name(const std::string &name);
		void set_manifest(std::shared_ptr<manifest> ptr);

		bool get_valid() const;

		std::string &get_manager_name();
		
		std::shared_ptr<plt_manager::manifest> get_manifest();		
		
		

	};
}
