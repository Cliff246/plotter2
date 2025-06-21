#pragma once

#include <iostream>
#include <mutex>
#include <ostream>
#include <string>

namespace plt_shared
{	
	enum logstate
	{
		LOG,
		WARNNING,
		ERROR,
	};

	void init_loggy();	
	void logg(const std::string &value);
	void logg(logstate state, const char *fmt, ...);	


	class loggy
	{
	protected:
	
			
	public:
		
		virtual void log(const std::string &value) = 0;	
		virtual std::string get_loggy_type() = 0; 
	};

	class loggy_console : public loggy 
	{
	private:
		std::ostream &m_output;	
		std::mutex m_mtx;
	public:

		loggy_console() : m_output(std::cout) {};
		void log(const std::string &value) override;
		std::string get_loggy_type() override;
	};

	extern plt_shared::loggy *loggy_current;
	extern plt_shared::loggy_console loggy_global;
}
