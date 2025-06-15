#pragma once

#include <filesystem> 
#include <plot.hpp>

#include <nlohmann/json.hpp>
#include "file_manager.hpp"

namespace plt_manager
{
	using json = nlohmann::json;
	class manifest 
	{
	private:
		path_fs m_manifest_path;
		json m_json;
		bool m_loaded;
	public:
			
		manifest(path_fs &path);
		~manifest();
		bool get_loaded();		
		void load_manifest();
		bool validate_manifest();
		

	};
}
