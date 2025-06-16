#pragma once
#include <memory>

#include "plotobject.hpp"
#include "plotscene.hpp"

namespace plt_shared
{
	using plotobj = class plotobj;
	class plot
	{
	private:
		std::shared_ptr<plt_shared::plotscene> scene;	
		
	public:
		plot();	
		~plot();

	};
}



