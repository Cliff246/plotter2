
#include "utils_threadworker.hpp"
#include <atomic>
#include <functional>
#include <mutex>

void plt_shared::threadworker::run()
{
	while (m_running)
	{
		std::function<void()> job;
		{
			std::unique_lock<std::mutex> lock(m_mtx);
			m_conditionvar.wait(lock, [&]{return !m_jobs.empty() || !m_running;});
			if(!m_running && m_jobs.empty())
				break;
			job = std::move(m_jobs.front());
			m_jobs.pop();
		}
		job();
	}
}

plt_shared::threadworker::~threadworker()
{
	{
	
		std::lock_guard<std::mutex> lock(m_mtx);
		m_running = false;
	}
	m_conditionvar.notify_one();
	if(m_thread.joinable())
		m_thread.join();
}

void plt_shared::threadworker::push(std::function<void()> arg)
{
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		m_jobs.push(std::move(arg));
	}
	m_conditionvar.notify_one();
}

