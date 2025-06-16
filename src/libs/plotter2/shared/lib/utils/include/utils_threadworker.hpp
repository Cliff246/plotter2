#pragma once 

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
namespace plt_shared
{
	class threadworker
	{
	private:
		std::thread m_thread;
		std::queue<std::function<void()>> m_jobs;
		std::mutex m_mtx;
		std::condition_variable m_conditionvar;
		std::atomic<bool> m_running;

		void run();
	public:
		threadworker() : m_thread([this] { run(); } ) {}
		~threadworker();

		void push(std::function<void()> arg);
	};

}
