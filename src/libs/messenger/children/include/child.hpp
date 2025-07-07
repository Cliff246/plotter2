#pragma once
#include <string>

namespace messenger 
{
	class sockchild
	{
	private:
		int m_socket;
		std::string m_path;
	public:
		sockchild();	
		void init(std::string &path);
		int set_up_socket();

	};
}
