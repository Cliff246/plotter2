
#include "loggy.hpp"
#include <cctype>
#include <mutex>
#include <string>
#include <format>
#include <stdarg.h>

namespace plt_shared
{
	plt_shared::loggy *loggy_current;
	plt_shared::loggy_console loggy_global;
}

void plt_shared::init_loggy()
{
	plt_shared::loggy_current = &plt_shared::loggy_global;
}

void plt_shared::logg(const std::string &log)
{
	static size_t count = 0;
	std::string formated = std::format("{}: {}", count, log);
	count++;
	plt_shared::loggy_current->log(formated);
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






void plt_shared::logg(plt_shared::logstate state, const char *fmt, ...) {
    if (!fmt) return;

    va_list args;
    va_start(args, fmt);

    // 1) figure out how big the formatted string will be
    va_list args_copy;
    va_copy(args_copy, args);
    int needed = std::vsnprintf(nullptr, 0, fmt, args_copy);
    va_end(args_copy);

    if (needed < 0) {
        va_end(args);
        return; // formatting error
    }

    // 2) allocate exactly that much (+1 for '\0')
    std::string buf;
    buf.resize(static_cast<size_t>(needed) + 1);

    // 3) actually format into it
    std::vsnprintf(buf.data(), buf.size(), fmt, args);
    va_end(args);

    // 4) drop the trailing '\0'
    buf.resize(static_cast<size_t>(needed));

    // 5) forward to your string‐based logger
    plt_shared::logg(buf);
	//thanks chatgpt
}

