#pragma once

#include <functional>
#include <vector>
#include <condition_variable>
#include <queue>
#include <mutex>
#include <atomic>
#include <thread>

namespace plt_shared
{
	class threadpool
	{
	private:
		int pool_id;
		std::vector<std::thread> m_threads;
		std::queue<std::function<void()>> m_tasks;
		std::mutex m_mutex;
		std::condition_variable m_conditionvar;
		std::atomic<bool> stop = false;
	
		void worker();
	public:
		
		threadpool(size_t pool_size);
		~threadpool();
		
	};
}
