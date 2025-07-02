#pragma once

#include "fhold.hpp"
#include "fholdtypes/file_holder.hpp"
#include "dataholder.hpp"
#include <memory>
#include <vector>


namespace datter
{
	
	class datasrc 
	{
	
	private:
			
	protected:
		std::shared_ptr<plt_shared::fhold> m_holder;
		bool loaded;	
	public:
		
		virtual std::string get_type() const = 0;	
		virtual bool set_file(plt_shared::path_fs &path) = 0; 
		virtual std::vector<std::vector<datahold_ptr>> get_data() = 0;	
	};
}
