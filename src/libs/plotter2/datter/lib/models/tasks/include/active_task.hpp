#pragma once




#include <memory>
#include "task.hpp"
#include "task_context.hpp"
#include "tasker.hpp"

namespace datter
{
	class active_task
	{
	private:
		std::unique_ptr<task_context> m_task_context;
		//the tasker running it 
		std::shared_ptr<tasker> m_tasker;
		//the latent task it's running from.
		std::unique_ptr<task> m_task;
	public:
	};
}
