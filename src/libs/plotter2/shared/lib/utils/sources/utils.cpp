#include "utils.hpp";
#include <vector>


using namespace plt_shared;



std::vector<std::string> plt_shared::split_string(const std::string &orgin, char delim)
{
	std::vector<std::string> splits; 
	
	size_t pos = 0;
	bool delimlast = false;
	for(size_t i = 0; i < orgin.length(); ++i)
	{	
		//                         we check last
		//                     \   /
		//is going forward ***  *** 
		//so if there were no delims before we add
		if(orgin[i] == delim)
		{		
			if(!delimlast)
			{
				std::string temp = orgin.substr(pos, i - pos); 
				splits.push_back(temp);
			}
			delimlast = true;
		}
		//not delim	
		else 
		{
			if(delimlast)
				pos = i;
			delimlast = false;
		}
	}
	if(!delimlast)
	{
		std::string temp = orgin.substr(pos); 
		splits.push_back(temp);
	}
	return splits;
}
