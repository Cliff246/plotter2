#include "testscommons.hpp"
#include <iostream>
#include <cstdlib>

std::vector<std::string> get_open_proccesses()
{
	std::FILE *file = popen("ps aux", "r");
	std::vector<std::string> ps_aux_results;

	if(file == nullptr)
	{
		return ps_aux_results;
	}

	const size_t buffer_size = 10000;
	char buffer[buffer_size];
	const std::string delim = "\n";
	std::string spill_over = "";
	size_t pos = 0;
	
	while(std::fgets(buffer, buffer_size, file))
	{
		
		std::string temp(buffer);
		//get lines
		while(1)
		{
			
			//to set overfill
			if((pos = temp.find(delim)) == std::string::npos)
			{
				spill_over = temp;
				break;
			}
			//to check over fill
			std::string token; 
			if(!spill_over.empty())
			{
				token = spill_over + temp.substr(0, pos);					
				spill_over.erase();
			}
			else
			{
				token = temp.substr(0, pos);
			}
			token = temp.substr(0, pos);

			ps_aux_results.push_back(temp);
			temp.erase(0, pos + delim.size());

		}

		
	}	

	return ps_aux_results;
}
