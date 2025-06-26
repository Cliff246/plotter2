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
		//can cache
		//this is TODO but it essentually means we store the cache life cycle to prevent a bunch of rereading
			
		virtual bool can_cache() = 0;	
		//is openable like a file handle
		virtual bool can_open() = 0;		
		//the file type
		virtual filetype get_fholdtype() = 0;
		//resolve if the data actually exists
		virtual bool does_exist() const = 0;
	};	
	using fhold_ptr = std::shared_ptr<fhold>;	
	//base class for file holder

	

}
