#include "datasrc_csv.hpp"
#include "dataholders/dataholder_string.hpp"
#include <stdexcept>
#include <string>
#include <memory>
#include <vector>

using namespace datter;

datasrc_csv::datasrc_csv()
{

}

datasrc_csv::~datasrc_csv()
{
	
}

std::string datasrc_csv::get_type() const 
{
	return "csv";
}

bool datasrc_csv::set_file(plt_shared::path_fs &path)
{
	m_holder = std::make_shared<plt_shared::file_holder>(path);
	if(m_holder->can_open() && m_holder->does_exist())
	{
		loaded = true;
		return true;
	}
	loaded = false;
	return false;
}	



std::vector<std::vector<datahold_ptr>> datasrc_csv::get_data() 
{



	std::vector<std::vector<datahold_ptr>> datarows ;
	if(loaded == false)
	{
		return datarows;
	}

	if(m_holder->get_fholdtype() != plt_shared::file)
	{
		throw std::runtime_error("cannot load from a non file fhold type");
	}

	std::vector<datahold_ptr> first;
	datarows.push_back(first);

	plt_shared::file_holder *file = static_cast<plt_shared::file_holder *>(&*m_holder);


	file->open_file(std::ios::in);
	

	std::string filedata = file->read_all();	

	//parse the csv
	size_t lines = 0;
	//where the section starts
	//are we quoted
	int64_t in_quote = 0;	

	//how much " are deep we ie """ is 3 meaning similarly "" = 2 and " = 1
	int64_t brackets_continued = 0;
	//
	std::string buffer;
	//
	if(filedata.length() == 1)
	{
		return datarows; 
	}	
	for(int i = 0; i < filedata.length(); ++i)
	{
		//determines brackets begin
		
		if(filedata[i] == '\"')
		{
			brackets_continued += 1;
			continue;
		}
		else
		{
			switch(brackets_continued)
			{
				case 1:
				{
					//enter or exit quote
					in_quote = (in_quote == 1)? 0: 1;
					break;
				}
				case 2:
				{
					//print "
					buffer += '\"';
					break;
				}
				case 3:
				{
					//print " and exit or enter
					buffer += '\"';
					in_quote = (in_quote == 1)? 0: 1;
					break;
				}
				default:
				{
					//reset > 3 or at error
					brackets_continued = 0;
					break;
				}		
			
			}
			if(filedata[i] == ',' && in_quote == 0)
			{
				//before the chunk is set 
			
				if(brackets_continued == 2)
				{
					buffer = "\"\"";
				}
				//TODO
				//do data parsing for integers and more
				std::string sub = buffer; 
				//
				auto dptr = std::make_shared<dataholder::datahold_string>();	
			
				dptr->set_string(sub);
				datarows[lines].push_back(dptr);	
			

				//after the chunk is set
				//clean buffer	
				buffer.clear();
			}
	
			else if(filedata[i] == '\n' && in_quote == 0)
			{
				//TODO
				//fix on windows
				std::string sub = buffer; 
				//TODO
				//do data parsing for integers and more
				auto dptr = std::make_shared<dataholder::datahold_string>();	
				dptr->set_string(sub);
				datarows[lines].push_back(dptr);	
				//chunk, should be simple
				std::vector<datahold_ptr> cols;
				datarows.push_back(cols);
				lines++;
			
				buffer.clear();
			}
			else
			{
				//add to new line
				buffer += filedata[i];
			}
			//on non bracket set to 0
			brackets_continued = 0;
		}

		

		
			
	}

	return datarows;

}



std::vector<std::vector<std::string>> datasrc_csv::get_data_string()
{
	std::vector<std::vector<std::string>> datarows ;
	if(loaded == false)
	{
		return datarows;
	}
	if(m_holder->get_fholdtype() != plt_shared::file)
	{
		throw std::runtime_error("cannot load from a non file fhold type");
	}

	plt_shared::file_holder *file = static_cast<plt_shared::file_holder *>(&*m_holder);


	std::vector<std::string> first;
	datarows.push_back(first);
	file->open_file(std::ios::in);
	

	std::string filedata = file->read_all();	

	//parse the csv
	size_t lines = 0;
	//where the section starts
	//are we quoted
	int64_t in_quote = 0;	

	//how much " are deep we ie """ is 3 meaning similarly "" = 2 and " = 1
	int64_t brackets_continued = 0;
	//
	std::string buffer;
	//
	if(filedata.length() == 1)
	{
		return datarows; 
	}	
	for(int i = 0; i < filedata.length(); ++i)
	{
		//determines brackets begin
		
		if(filedata[i] == '\"')
		{
			brackets_continued += 1;
			continue;
		}
		else
		{
			switch(brackets_continued)
			{
				case 1:
				{
					//enter or exit quote
					in_quote = (in_quote == 1)? 0: 1;
					break;
				}
				case 2:
				{
					//print "
					buffer += '\"';
					break;
				}
				case 3:
				{
					//print " and exit or enter
					buffer += '\"';
					in_quote = (in_quote == 1)? 0: 1;
					break;
				}
				default:
				{
					//reset > 3 or at error
					brackets_continued = 0;
					break;
				}		
			
			}
			if(filedata[i] == ',' && in_quote == 0)
			{
				//before the chunk is set 
			
				if(brackets_continued == 2)
				{
					buffer = "\"\"";
				}
				//TODO
				//do data parsing for integers and more
				std::string sub = buffer; 
				//
			
				datarows[lines].push_back(sub);	
			

				//after the chunk is set
				//clean buffer	
				buffer.clear();
			}
	
			else if(filedata[i] == '\n' && in_quote == 0)
			{
				//TODO
				//fix on windows
				std::string sub = buffer; 
				//TODO
				//do data parsing for integers and more
				datarows[lines].push_back(sub);	
				std::vector<std::string> cols; 
				datarows.push_back(cols);
				lines++;
			
				buffer.clear();
			}
			else
			{
				//add to new line
				buffer += filedata[i];
			}
			//on non bracket set to 0
			brackets_continued = 0;
		}

		

		
			
	}

	return datarows;

}
