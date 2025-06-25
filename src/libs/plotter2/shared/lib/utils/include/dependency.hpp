#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include "fhold.hpp"

namespace plt_shared
{
	class dependency
	{
	private:
		std::string m_dependency_key;
		fhold_ptr m_holder;	
		std::vector<std::shared_ptr<dependency>> m_dependencies;
			
		bool can_resolve();

	public:
		dependency();
		~dependency();	
		
	};
}
