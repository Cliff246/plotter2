#include "scripter.hpp"
#include <_types/_nl_item.h>
#include <exception>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <unistd.h>

//init script from path
plt_shared::script::script(path_fs &path)
{
	m_script_path = path;
	m_loaded = false;
	m_initalized = false;
}


//load content
void plt_shared::script::load_script()
{
	if(m_loaded)
		return;
	//forward declare script_stream
	std::ifstream script_stream;
	try 
	{	
		//open path
		script_stream.open(m_script_path);
			
		//start up string stream
		std::ostringstream string_stream;
		//pipe script_stream into string_stream
		string_stream << script_stream.rdbuf();
		//get content		
		m_script_content = string_stream.str();
		//close
		script_stream.close();	
		//set loaded
		m_loaded = true;
		return;
	}
	catch(const std::exception &e) 
	{
		if(script_stream.is_open() == true) 
		{
			script_stream.close();
		}	
		throw e;
	}
	
	
}	
	
//get script_content if it succeds and not if it not been loaded
std::string &plt_shared::script::get_script_content()
{
	if(m_loaded == true)
	{
		return m_script_content;
	}
	else
	{
		throw std::runtime_error("script has not loaded it's content's yet");
	}
}



bool plt_shared::script::get_loaded()
{
	return m_loaded;
}
