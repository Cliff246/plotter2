#pragma once

#include "datasrc.hpp"
#include "dataholder.hpp"
#include <vector>

namespace datter
{

	class datasrc_csv : public datasrc
	{
	private:

	public:	
		~datasrc_csv();
		datasrc_csv();
		std::string get_type() const override;
		bool set_file(plt_shared::path_fs &path) override; 

		std::vector<std::vector<datahold_ptr>> get_data() override;	


		std::vector<std::vector<std::string>> get_data_string();	

		
	};	


}
