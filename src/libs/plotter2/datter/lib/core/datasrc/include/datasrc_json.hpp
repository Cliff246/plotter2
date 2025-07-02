#pragma once

#include "datasrc.hpp"

#include <nlohmann/json.hpp>

namespace datter
{
	class datasrc_json : public datasrc
	{
		using json = nlohmann::json;
	private:

		json m_json; 
	public:
		datasrc_json();
		~datasrc_json();

		std::string get_type() const override;	
		bool set_file(plt_shared::path_fs &path) override; 
		std::vector<std::vector<datahold_ptr>> get_data() override;	
	
	};
}
