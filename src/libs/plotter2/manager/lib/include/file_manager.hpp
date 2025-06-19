#pragma once

#include <memory>
#include <vector>

#include "utils_fileholder.hpp"

namespace plt_manager
{

	
		

	using plt_shared::path_fs;	

	class directory_manager 
	{
	private:
		//list of the files in the directory
		std::vector<std::shared_ptr<plt_shared::fhold>> m_directory;

		//source path
		path_fs m_path;
		
		
	public:
		
		directory_manager(path_fs &path);
		~directory_manager();
	

	};
}
