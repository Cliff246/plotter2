#include "manifest.hpp"
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>

plt_manager::manifest::manifest(path_fs &path)
{
	
	m_manifest_path = path;		
	
	std::ifstream istream;
	try
	{
		istream.open(path);
		//try to open path	
		m_json = json::parse(istream);	
	
		istream.close();
		m_loaded = true;
		return;	
	}
	catch(const std::exception &e)
	{
		if(istream.is_open())
		{
			istream.close();
		}
		std::cerr << "could not parse the json " << path.string() << "\n";
	}

}


plt_manager::manifest::~manifest()
{

}


bool plt_manager::manifest::get_loaded()
{
	return m_loaded;
}	

#define TUP(x,y) std::make_tuple(x,y)
//required


enum json_types 
{
	jstr,
	jmap,
	jnum,	
	jary,
	jnil,
	unknown
};	

const std::array<std::tuple<std::string, json_types>, 16> manifest_required = 
{
	TUP("date", jstr),
	TUP("time", jnum),
	TUP("timezone", jstr),
	TUP("manifest_version", jnum),
	TUP("orgin_point", jstr),
	TUP("destination", jstr),
	TUP("comunication_type", jmap),
	TUP("user", jstr),
	TUP("meta", jmap),
	TUP("preprocessor", jmap),
	TUP("tasks", jmap),
	TUP("plots", jmap),
	TUP("style", jmap),
	TUP("custom_render_templates", jmap),
	TUP("directory_tree", jmap),
	TUP("render_kit", jstr)
};
#undef TUP

/*
 
	 
 
 
 

*/



//convert the niohmann json to the custom type
json_types libjson_to_json_types(plt_manager::json arg)
{
	if(arg.is_object())
		return jmap;
	else if(arg.is_string())
		return jstr;
	else if(arg.is_null())
		return jnil;
	else if(arg.is_number())
		return jnum;
	else if(arg.is_array())
		return jary;
	else 
		return unknown; 
}

void plt_manager::manifest::load_manifest()
{
	if(m_loaded == true)
	{
				
	}	
}


bool plt_manager::manifest::validate_manifest()
{
	if(!m_loaded) 
		return false;
	if(m_json.empty())
		return false;	
	int count = 0;
	//this is stupid but fuck it
	for(auto &elem : manifest_required)
	{
		const std::string &elem1 = std::get<0>(elem);	
		const json_types &elem2 = std::get<1>(elem);
		
		if(m_json.contains(elem1))
		{
			json_types type = libjson_to_json_types(m_json[elem1]);
			if(type == elem2)
			{
				count++;	
			}
		}
		else
		{
			std::cout << "we are " <<elem1 << " missing\n";
		}
		

	}
	const size_t size = manifest_required.size();
	std::cout << size << " " << count << "\n";
	if(count == size)
		return true;
	return false;
}	
