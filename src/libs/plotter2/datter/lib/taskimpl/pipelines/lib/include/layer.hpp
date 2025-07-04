#pragma once

#include <memory>
#include "plotscene.hpp"

namespace plt_pipeline
{

	class layer
	{
	private:
		std::vector<std::string> m_exposed;
	
	public:

		virtual std::string get_type() const = 0;	
		
		virtual bool must_load() const = 0;
		
		virtual plt_shared::plotscene &transform_scene(plt_shared::plotscene &) = 0;	
	};
	using layer_ptr = std::shared_ptr<plt_pipeline::layer >;

}
