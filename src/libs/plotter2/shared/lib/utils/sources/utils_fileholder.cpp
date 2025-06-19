#include "utils_fileholder.hpp"
#include <exception>
#include <fstream>
#include <sstream>
#include <ios>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <set>
plt_shared::fileholder::fileholder(plt_shared::path_fs path) 
{
	m_path = path;
	m_loaded = false;

}

plt_shared::fileholder::~fileholder()
{
	if(m_loaded == true)
	{
		m_stream.close();
	}
}

bool plt_shared::fileholder::can_open()
{
	return true;
}	

plt_shared::filetype plt_shared::fileholder::get_filetype()
{
	return plt_shared::filetype::file;
}

bool plt_shared::fileholder::does_exist() const
{
	bool output = std::filesystem::exists(m_path);	
	return output; 
}

bool plt_shared::fileholder::is_loaded() 
{
	return m_loaded;
}

bool plt_shared::fileholder::open_file(std::ios_base::openmode flags)
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

bool plt_shared::fileholder::can_write() const
{
	return (m_flags & std::ios::out)? true : false;
}

bool plt_shared::fileholder::can_read() const
{
	bool canread = (m_flags & std::ios::in)? true : false;

	return canread; 
}


char plt_shared::fileholder::read()
{
	if(is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	char value;
	return value;
}

std::string plt_shared::fileholder::read_line()
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
std::string plt_shared::fileholder::read_all()
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

std::vector<char> plt_shared::fileholder::read_bytes()
{
	if(!is_loaded() || !can_read())
	{
		throw std::runtime_error("cannot read from a file that's not loaded or readable");
	}
	std::vector<char> content; 
	return content;	
	
}

void plt_shared::fileholder::set_seek(size_t seek)
{
	if(is_loaded())
	{
		set_seekw(seek);
		set_seekr(seek);
	}	
}

void plt_shared::fileholder::set_seekr(size_t seek)
{
	if(is_loaded() && can_read())
	{
		m_stream.seekg(seek);
	}
}

void plt_shared::fileholder::set_seekw(size_t seek)
{
	if(is_loaded() && can_write())
	{

		m_stream.seekp(seek);
	}
}
	
bool plt_shared::fileholder::has_aligned_seek()
{
	if(m_stream.tellg() == m_stream.tellp())
	{
		return true;
	}
	return false;
}

//weird one but it get's the seek if they are aligned and get's -1 if it's not aligned. 
int64_t plt_shared::fileholder::get_seek()
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
size_t plt_shared::fileholder::get_seekr()
{
	if(is_loaded() && can_read())
	{
		return m_stream.tellg();
	}
	return 0;
}

size_t plt_shared::fileholder::get_seekw()
{
	if(is_loaded() && can_read())
	{
		return m_stream.tellg();
	}
	return 0;
}

size_t plt_shared::fileholder::get_size()
{
	std::streampos current = m_stream.tellg();
    // Go to end
    m_stream.seekg(0, std::ios::end);
    std::streamsize size = m_stream.tellg();
    // Restore position
    m_stream.seekg(current);
    return size;
}





bool plt_shared::directoryholder::can_open()
{
	return false;
}
plt_shared::filetype plt_shared::directoryholder::get_filetype()
{
	return plt_shared::filetype::directory;
}
bool plt_shared::directoryholder::does_exist() const
{
	return std::filesystem::exists(m_path);	
}


plt_shared::fhold_ptr plt_shared::directoryholder::get_holder(const std::string &key)
{
	return m_map[key];
}
		
std::set<std::string> plt_shared::directoryholder::get_keys()
{
	//sketchy 
	std::set<std::string> keys;
	for(const auto &pair : m_map)
	{
		keys.insert(pair.first);
	}
	return keys;	
}
std::set<plt_shared::fhold_ptr> plt_shared::directoryholder::get_values()
{
	std::set<plt_shared::fhold_ptr> values;
	for(const auto &pair : m_map)
	{
		values.insert(pair.second);
	}
	return values;
}

