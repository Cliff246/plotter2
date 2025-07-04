#pragma once

#include <memory>
#include <vector>

#if CHILD == 0

namespace datter
{
	
	class bundle_node
	{
	private:
		//outgoing neigbours for the bundle 
		std::vector<std::shared_ptr<bundle_node>> m_neighbours;	
		int64_t m_name;


	public:
	};
	
}

#endif

