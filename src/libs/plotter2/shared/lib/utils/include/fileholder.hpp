#pragma once

#include <filesystem>
#include <ios>
#include <iostream>
#include <fstream>
#include <vector>

namespace plt_shared
{
	using path_fs = std::filesystem::path;  
	enum filetype
	{
		file, 
		directory,
			
	};

	

	//base class for file holder
	class fileholder
	{
	private:
		//file type(unused right now)
		filetype m_filetype;
		//stream
		std::fstream m_stream;
		//path 
		path_fs m_path;
		//loaded bool... cause it's needed for later
		bool m_loaded = false; 
		//flags 
		std::ios_base::openmode m_flags;
	public:	
		//set with file
		fileholder(path_fs path);	
		~fileholder();
		//checks if exists duh
		//
		
		bool does_exist() const;
		bool is_loaded();
		bool can_write() const;
		bool can_read() const;


		//open file for reading
		bool open_file(std::ios_base::openmode flags);
		//closes file
		void close_file();
		//writes
		//not implemeented just yet
		void write();	
		//reads 
		//read a character(don't use)
		char read();
		//reads the next line 
		std::string read_line();
		//reads the rest of the file
		std::string read_all();
		//reads the rest of the file as bytes... pretty much the same as readall
		std::vector<char> read_bytes();
		//set seeks 
		//set both seekr and seekw safely and does one or the other if it can't 
		void set_seek(size_t seek);
		//set seek read head(assuming you have read perms)
		void set_seekr(size_t seek);
		//set seek write head(assuming you have write perms)
		void set_seekw(size_t seek);
		
		//checks if both seeks are aligned 	
		bool has_aligned_seek();
	
		//weird one but it get's the seek if they are aligned and get's -1 if it's not aligned. 
		int64_t get_seek();
		//get's seek read
		size_t get_seekr();
		//get's seek write
		size_t get_seekw();

		//just get size in bytes
		size_t get_size();

	};
}
