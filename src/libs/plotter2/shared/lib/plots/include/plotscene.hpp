#pragma once

#include "plotobject.hpp"


namespace plt_shared
{
	class plotscene
	{
	private:
		plotobj_ptr head;
		
	public:
		plotscene();
		~plotscene();	
	};
}
