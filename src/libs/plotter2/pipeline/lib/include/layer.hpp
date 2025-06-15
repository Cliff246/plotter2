#pragma once

#include <memory>
#include "scripter.hpp"
#include "plotscene.hpp"

namespace plt_pipeline
{
	class layer
	{
	private:
		std::shared_ptr<plt_shared::script> script;

	public:
		layer();
		~layer();
		plt_shared::plotscene &transform_scene(plt_shared::plotscene &);	
	};
}
