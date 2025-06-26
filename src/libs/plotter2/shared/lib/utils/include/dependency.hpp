#pragma once

#include <memory>
#include <type_traits>
#include <vector>
#include <set>
#include "fhold.hpp"

namespace plt_shared
{
	class dependency
	{
	private:

		std::string m_dependency_key;
		//shared pointer
		fhold_ptr m_holder;	
		std::vector<std::shared_ptr<dependency>> m_dependencies;
			
		bool can_resolve();
		bool is_resolved();
		bool is_ready_instance(std::set<std::string> &set);
	public:
		dependency(std::string &key);
		~dependency();	
	

		bool is_ready();	


		//
		std::string get_dependkey() const;
		//grab holder
		fhold_ptr get_holder() const;
		//don't double set
		void set_holder(fhold_ptr hold);

	};
}
