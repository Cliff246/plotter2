
#pragma once

#include <vector>

#include "bundle_element.hpp"

#if CHILD == 0

namespace datter
{
	//container for the content of a bundle.
	class bundle_container
	{
	private:
		bool m_pool;
		std::vector<bundle_element> m_elements;

		std::string m_key;


	public:
	};
}
#endif
