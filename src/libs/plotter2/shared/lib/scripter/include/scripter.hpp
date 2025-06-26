#pragma once

#include <Python.h>
#include <vector>
#include <memory>
#include "fhold.hpp"
#include "exposed.hpp"

namespace plt_shared
{

	class script
	{
	private:
			
		//file holder	
		std::shared_ptr<fhold> m_file;
		
		std::vector<std::unique_ptr<exposed>> m_exposed;
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
