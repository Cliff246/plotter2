#include "datasrc_csv.hpp"
#include "dataholders/dataholder_string.hpp"
#include <memory>
#include <vector>

plt_shared::datasrc_csv::datasrc_csv()
{

}

plt_shared::datasrc_csv::~datasrc_csv()
{
	
}

const std::string plt_shared::datasrc_csv::get_type() const 
{
	return "csv";
}

bool plt_shared::datasrc_csv::set_file(plt_shared::path_fs &path)
{
	m_holder = std::make_shared<fileholder>(path);
	if(m_holder->can_open() && m_holder->does_exist())
	{
		loaded = true;
		return true;
	}
	loaded = false;
	return false;
}	



std::vector<std::vector<plt_shared::datahold_ptr>> plt_shared::datasrc_csv::get_data() 
{
	std::vector<std::vector<plt_shared::datahold_ptr>> datarows ;
	if(loaded == false)
	{
		return datarows;
	}

	std::vector<datahold_ptr> first;
	datarows.push_back(first);
	m_holder->open_file(std::ios::in);
	

	std::string filedata = m_holder->read_all();	

	//parse the csv
	size_t lines = 0;
	//where the section starts
	int64_t chunkstart = -1;	
	
	//how much 'in_quote' are  we ie """hello""" is 3 meaning to get out we need "" and a "
	int64_t in_quote = 0;	
	//how many brackets are counted in series, resets on anything else
	int64_t brackets_continued = 0;
	//last character
	char lastchar = '\0';
	

	for(int i = 0; i < filedata.length(); ++i)
	{
		//determines brackets begin
		if(filedata[i] == '\"')
		{
			brackets_continued++;	
		}
		//brackets end
		if(filedata[i] != '\"' && lastchar == '\"')
		{
			if(brackets_continued == in_quote)
				in_quote--;
			else if(brackets_continued == in_quote + 1) 
				in_quote++;
			
			brackets_continued = 0;	
		}
		//comma section
		if(filedata[i] == ',' && in_quote <= 0)
		{
			//before the chunk is set 
			
			std::string sub = filedata.substr(chunkstart + 1, i - chunkstart - 1);

			auto dptr = std::make_shared<dataholder::datahold_string>();	
			dptr->set_string(sub);
			datarows[lines].push_back(dptr);	
			

			chunkstart = i;	
			//after the chunk is set


		}
		if(filedata[i] == '\n')
		{
			std::string sub = filedata.substr(chunkstart + 1, i - chunkstart - 1);

			auto dptr = std::make_shared<dataholder::datahold_string>();	
			dptr->set_string(sub);
			datarows[lines].push_back(dptr);	
			//chunk, should be simple
			std::vector<datahold_ptr> cols;
			datarows.push_back(cols);
			lines++;
			chunkstart = i;	
		}
		else if(filedata[i] == '\n' && lastchar == '\r')
		{
			//windows chunk and more complicated but just remove the \r
			std::vector<datahold_ptr> cols;
			datarows.push_back(cols);
			lines++;
			chunkstart = i;	
		}	

		lastchar = filedata[i];
	}

	return datarows;

}
