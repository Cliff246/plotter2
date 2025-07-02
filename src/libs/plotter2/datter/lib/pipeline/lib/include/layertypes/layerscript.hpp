#pragma once
#include "scripter.hpp"
#include "layer.hpp"

namespace plt_pipeline
{
	class layerscript : public layer 
	{
	private:

	
		std::shared_ptr<plt_shared::script> script;
	public:
		layerscript();
		~layerscript();

		std::string get_type() const override;	
		
		bool must_load() const override;
		plt_shared::plotscene &transform_scene(plt_shared::plotscene &) override;	
	};
}
