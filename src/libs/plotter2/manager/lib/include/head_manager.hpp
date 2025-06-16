#pragma once

#include "manager.hpp"
#include <memory>
#include <vector>
#include <queue>
namespace plt_manager
{
	using manager_ptr = std::shared_ptr<plt_manager::manager>;

	class headmanager
	{
	private:
		std::vector<manager_ptr> m_managers;
		std::queue<manager_ptr> m_currently; 
		size_t m_activesize;
		size_t m_activelimit;
	public:
		

		headmanager(size_t maxsize, size_t maxlimit);


		void push_new_task(path_fs path);
	};
}
