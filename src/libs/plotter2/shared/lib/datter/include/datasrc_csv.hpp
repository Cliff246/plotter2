#pragma once

#include "datasrc.hpp"
#include "dataholder.hpp"
#include <vector>

namespace plt_shared
{

	class datasrc_csv : public datasrc
	{
	private:

	public:	
		~datasrc_csv() override;
		const std::string get_type() const override;
		bool set_file(path_fs &path) override; 

		std::vector<std::vector<datahold_ptr>> get_data() override;	


		
	};	
}
