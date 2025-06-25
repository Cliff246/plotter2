#include "scripter.hpp"
#include <exception>
#include <memory>
#include <stdexcept>
#include <unistd.h>

#include "fholdtypes/file_holder.hpp"
//init script from path
plt_shared::script::script(plt_shared::path_fs &path)
{
	m_file = std::make_shared<file_holder>(path);
	m_loaded = false;
	m_initalized = false;
}


//load content
void plt_shared::script::load_script()
{
	if(m_loaded)
		return;
	//forward declare script_stream
	try 
	{	
		if(m_file->get_fholdtype() != file)
			throw std::runtime_error("cannot open fhold of wrong type");
		//open path
		plt_shared::file_holder *file = static_cast<plt_shared::file_holder*>(&*m_file);
		file->open_file(std::ios::in);
			
		m_script_content = file->read_all();
		file->close_file();
		//set loaded
		m_loaded = true;
		return;
	}
	catch(const std::exception &e) 
	{
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
