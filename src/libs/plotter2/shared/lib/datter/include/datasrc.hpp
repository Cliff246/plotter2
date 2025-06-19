#pragma once

#include "utils_fileholder.hpp"
#include "dataholder.hpp"
#include <memory>
#include <vector>


namespace plt_shared
{
	
	class datasrc 
	{
	
	private:
			
	protected:
		std::shared_ptr<fileholder> m_holder;
		bool loaded;	
	public:
		
		virtual const std::string get_type() const = 0;	
		virtual bool set_file(path_fs &path) = 0; 
		virtual std::vector<std::vector<datahold_ptr>> get_data() = 0;	
	};
}
