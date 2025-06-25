#pragma once

#include <Python.h>
#include <fhold.hpp>
#include <memory>
#include "exposed.hpp"

namespace plt_shared
{

	class script
	{
	private:
			
		//file holder	
		std::shared_ptr<fhold> m_file;
		

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
