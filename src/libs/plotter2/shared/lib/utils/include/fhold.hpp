#pragma once

#include <filesystem>
#include <map>

namespace plt_shared
{
	using path_fs = std::filesystem::path;  
	enum filetype
	{
		file, 
		directory,
			
	};

	class fhold
	{
	protected: 	
		filetype m_filetype;
		bool m_cached;
	public:
		
			
		virtual bool get_cached();
		virtual bool can_cache() = 0;	
		virtual bool can_open() = 0;		
		virtual filetype get_fholdtype() = 0;
		virtual bool does_exist() const = 0;
	};	
	using fhold_ptr = std::shared_ptr<fhold>;	
	//base class for file holder

	

}
