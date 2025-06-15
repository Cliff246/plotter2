#pragma once

#include <Python.h>
#include <filesystem>


namespace plt_shared
{
	using path_fs = std::filesystem::path;  

	class script
	{
	private:
		//script path
		path_fs m_script_path;
		//script_content
		std::string m_script_content;	
		//file is in memory(DOES NOT MEAN IT'S READY)
		bool m_loaded;
		bool m_initalized;
	
				
	public:
		script(path_fs &path);
		~script();

		void load_script();		
		std::string &get_script_content();
		bool get_loaded();
	};
}
