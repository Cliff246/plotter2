#include "messager_commons.hpp"
#include <unistd.h>

using namespace messenger;


bool messenger::safe_close(int32_t fd)
{
	if(fd >= 0)
	{
		if(close(fd) == -1)
		{
			return false;
		}	
		return true;
	}
	return false;
}
