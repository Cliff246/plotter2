#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <memory>

#include "plotobject.hpp"
#include "plotscene.hpp"

namespace plt_shared
{
	using plotobj = class plotobj;
	class plot
	{
	private:
		plt_shared::plotscene scene;	
	public:
		plot();	
	};
}



