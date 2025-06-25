#pragma once

#include <filesystem>
#include <ios>
#include <iostream>
#include <fstream>
#include <memory>
#include <set>
#include <vector>
#include <map>

#include "fhold.hpp"

namespace plt_shared
{
	class directory_holder : public fhold
	{
	private:
		path_fs m_path;
		std::map<std::string, fhold_ptr> m_map;
	public:
		directory_holder();
		~directory_holder();

		bool can_open() override;
		filetype get_fholdtype() override;
		bool does_exist() const override;
		bool can_cache() override;	

		fhold_ptr get_holder(const std::string &key);
		
		std::set<std::string> get_keys();
		std::set<fhold_ptr> get_values();
		
	};

}
