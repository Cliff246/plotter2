#pragma once

#include <memory>
#include "scripter.hpp"
#include "plotscene.hpp"

namespace plt_pipeline
{

	class layer
	{
	private:
		

	public:

		virtual std::string get_type() const = 0;	


		virtual plt_shared::plotscene &transform_scene(plt_shared::plotscene &) = 0;	
	};
	using layer_ptr = std::shared_ptr<plt_pipeline::layer >;

}
