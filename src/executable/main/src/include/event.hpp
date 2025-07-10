#pragma once

#include <string>

namespace p2exe
{

	enum event_type
	{
		EVNT_proccess_failed,
		EVNT_proccess_startup,
		EVNT_proccess_heldup,
		EVNT_none,	
	};

	class event
	{
	private:
		event_type m_type;
		std::string &m_message;	

	public:

		event_type get_type() const;
	};
}
