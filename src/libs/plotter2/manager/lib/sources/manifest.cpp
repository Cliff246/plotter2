#include "loggy.hpp"
#include "manifest.hpp"
#include <array>
#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
#include <format>

using namespace plt_manager;

plt_manager::manifest::manifest(const path_fs &path)
{
	
	m_manifest_path = path;		
	//basic and old but should work	
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

const std::array<std::string, 4> key_for_path = 
{
	"path",
	"alias",
	"directory",
	"source",
};


#define TUP(x,y) std::make_tuple(x,y)
//required



const std::vector<field_reqiuriment> manifest_required = 
{
	{"date", jstr},
	{"time", jnum},
	{"timezone", jstr},
	{"user", jstr},
	{"manifest_version", jnum},
	{"meta", jmap},
	{"orgin_point", jstr},
	{"destination", jstr},
	{"directory_tree", jmap},
	{"comunication_type", jmap},
	{"preprocessor", jmap},
	{"tasks", jmap},
	{"plots", jmap},
	{"style", jmap},
	{"custom_render_templates", jmap},
	{"render_kit", jstr}
};



#undef TUP

/*
 
	 
 
 
 

*/

std::string plt_manager::get_json_types_string(json_types type)
{
	switch(type)
	{
		case jmap:
			return "map";
		case jstr:
			return "str";
		case jnil:
			return "nil";
		case jnum:
			return "ary";
		default: 
			return "unk";
	}
}

//convert the niohmann json to the custom type
json_types plt_manager::libjson_to_json_types(plt_manager::json arg)
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
	std::vector<std::string> errors;
	for(auto &elem : manifest_required)
	{
		const std::string &elem1 = elem.m_field;	
		const json_types &elem2 = elem.m_type;
		
		if(m_json.contains(elem1))
		{
			json_types type = libjson_to_json_types(m_json[elem1]);
			if(type == elem2)
			{
				count++;	
			}
			else
			{
				std::string type = get_json_types_string(elem2);
				errors.push_back(std::format("type {} is incompatable with name {}", elem1, type));
			}
		}
		else
		{
			errors.push_back(std::format("cannot find name {} in manifest", elem1));
		}
		
		
		
	}
	//erros 
	if(!errors.empty())
	{
		plt_shared::logg("");
		plt_shared::logg(plt_shared::ERROR, "manifest validation failed");
		for (auto &e : errors) plt_shared::logg(plt_shared::ERROR, "  - %s \n", e.c_str());
		return false;
	}
	const size_t size = manifest_required.size();
	return (count >= size)? true : false;
}	


plt_manager::field_reqiuriment::~field_reqiuriment()
{
	delete m_children;
}
