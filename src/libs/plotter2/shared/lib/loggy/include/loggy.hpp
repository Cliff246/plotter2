#pragma once

#include <iostream>
#include <filesystem>
#include <mutex>
#include <ostream>
#include <string>
#include <type_traits>

namespace plt_shared
{
	void init_loggy();	
	void log(const std::string &value);
	
	
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

	extern loggy *loggy_current;
	extern loggy_console loggy_global;
}
