#pragma once

#include <filesystem> 
#include <memory>
#include <plot.hpp>

#include <nlohmann/json.hpp>
#include "file_manager.hpp"

namespace plt_manager
{
	using json = nlohmann::json;
	enum json_types 
	{
		jstr,
		jmap,
		jnum,	
		jary,
		jnil,
		unknown
	};
	std::string get_json_types_string(json_types type);	

	json_types libjson_to_json_types(plt_manager::json arg);
	struct field_reqiuriment
	{
		std::string	m_field;
		json_types m_type;
		std::vector<std::shared_ptr<field_reqiuriment>> *m_children = nullptr; 
		bool m_optional = false;
		

		~field_reqiuriment();
	};


	class manifest 
	{
	private:
		path_fs m_manifest_path;
		json m_json;
		bool m_loaded;
	public:
			
		manifest(const path_fs &path);
		~manifest();
		bool get_loaded();		
		void load_manifest();
		bool validate_manifest();
		

	};
}
