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
	class file_holder : public fhold
	{
	private:
		path_fs m_path;
		//file type(unused right now)
		//stream
		//
		std::fstream m_stream;
		//path 
		//loaded bool... cause it's needed for later
		bool m_loaded = false; 
		//flags 
		std::ios_base::openmode m_flags;
	public:	
		//set with file
		file_holder(path_fs path);	
		~file_holder();
		//checks if exists duh
		bool can_open() override;
		filetype get_fholdtype() override;
		bool does_exist() const override;
		bool is_loaded();
		bool can_write() const;
		bool can_read() const;

		bool can_cache() override;	

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
