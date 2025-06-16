
#include <mutex>
#include <string>
#include <format>
#include "loggy.hpp"

plt_shared::loggy_console loggy_global;
plt_shared::loggy *loggy_current;

void plt_shared::init_loggy()
{
	loggy_current = &loggy_global;
}

void plt_shared::log(const std::string &log)
{
	static size_t count = 0;
	std::string formated = std::format("{}: {}", count, log); 
	count++;
	loggy_current->log(formated);	
}



std::string plt_shared::loggy_console::get_loggy_type()
{
	std::string out = "CONSOLE";
	return out;
}


void plt_shared::loggy_console::log(const std::string &value)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	m_output << value << std::endl;
}
