#include "fhold.hpp"
#include "fholdtypes/file_holder.hpp"
#include <exception>
#include <fstream>
#include <sstream>
#include <ios>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <set>



plt_shared::file_holder::file_holder(plt_shared::path_fs path) 
{
	m_path = path;
	m_loaded = false;

}

plt_shared::file_holder::~file_holder()
{
	if(m_loaded == true)
	{
		m_stream.close();
	}
}

bool plt_shared::file_holder::can_open()
{
	return true;
}	

bool plt_shared::file_holder::can_cache()
{
	return true;
}	

plt_shared::filetype plt_shared::file_holder::get_fholdtype()
{
	return plt_shared::filetype::file;
}

bool plt_shared::file_holder::does_exist() const
{
	bool output = std::filesystem::exists(m_path);	
	return output; 
}

bool plt_shared::file_holder::is_loaded() 
{
	return m_loaded;
}

bool plt_shared::file_holder::open_file(std::ios_base::openmode flags)
{
	if(m_loaded == true)
	{
		//no duplicate loads
		return false;
	}
	try
	{	

		//set fstream
		m_stream.open(m_path);
		m_loaded = true;
		m_flags = flags;
		return true;
	}
	catch(const std::exception &e)
	{
		//just fuck it
		return false;
	}
}

bool plt_shared::file_holder::can_write() const
{
	return (m_flags & std::ios::out)? true : false;
}

bool plt_shared::file_holder::can_read() const
{
	bool canread = (m_flags & std::ios::in)? true : false;

	return canread; 
}


char plt_shared::file_holder::read()
{
	if(!is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	
	char value = m_stream.get();

	return value;
}

std::string plt_shared::file_holder::read_line()
{
	if(!is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	std::string line;
	std::getline(m_stream, line);
	return line;
}
//read_
std::string plt_shared::file_holder::read_all()
{
	if(!is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	std::stringstream buffer; 
	buffer << m_stream.rdbuf();
	std::string out = buffer.str();
	return out;
}

std::vector<char> plt_shared::file_holder::read_bytes()
{
	if(!is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	std::vector<char> content; 
	return content;	
	
}

void plt_shared::file_holder::set_seek(size_t seek)
{
	if(is_loaded())
	{
		set_seekw(seek);
		set_seekr(seek);
	}	
}

void plt_shared::file_holder::set_seekr(size_t seek)
{
	if(is_loaded() && can_read())
	{
		m_stream.seekg(seek);
	}
}

void plt_shared::file_holder::set_seekw(size_t seek)
{
	if(is_loaded() && can_write())
	{

		m_stream.seekp(seek);
	}
}
	
bool plt_shared::file_holder::has_aligned_seek()
{
	if(m_stream.tellg() == m_stream.tellp())
	{
		return true;
	}
	return false;
}

//weird one but it get's the seek if they are aligned and get's -1 if it's not aligned. 
int64_t plt_shared::file_holder::get_seek()
{
	if(!is_loaded())
	{
		return -1;
	}
	if(get_seekr() == get_seekw())
	{
		return get_seekr();
	}
	return -1;		
}
//get's seek read
size_t plt_shared::file_holder::get_seekr()
{
	if(is_loaded() && can_read())
	{
		return m_stream.tellg();
	}
	return 0;
}

size_t plt_shared::file_holder::get_seekw()
{
	if(is_loaded() && can_read())
	{
		return m_stream.tellg();
	}
	return 0;
}

size_t plt_shared::file_holder::get_size()
{
	std::streampos current = m_stream.tellg();
    // Go to end
    m_stream.seekg(0, std::ios::end);
    std::streamsize size = m_stream.tellg();
    // Restore position
    m_stream.seekg(current);
    return size;
}

