#pragma once
#include <string>

namespace plt_shared
{

	enum exposed_type
	{
		function,
		constant,
		paramaters,
		return_type,
	};

	class exposed
	{
	private:
		std::string m_public_exposed;
		std::string m_exposed_content;
		exposed_type m_exposed_type;
	public:

		exposed(std::string key, std::string value, exposed_type type);
		
		
		
	};
}
