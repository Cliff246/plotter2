#pragma once
#include <string>
#include <memory>

namespace plt_pipeline
{
	template<typename T> 
	class layerfeature
	{
	private:
		T feature;
		std::string m_key;	
		std::string m_feature_name;
	public:	

		layerfeature<T>(); 	

	};
	
	
	
}

