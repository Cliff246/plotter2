#pragma once
#include "iostream"
#include "string"

namespace pl2_manager
{
	class manager 
	{
	public:
		manager();
		~manager();

		std::string &get_manager_name();
	private:	

		std::string manager_name;
	};
}
