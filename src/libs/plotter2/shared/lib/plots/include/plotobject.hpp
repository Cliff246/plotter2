#pragma once

#include <map>
#include <memory>
#include <vector>

namespace plt_shared 
{
	//base class of plot object	
	class plotobj 
	{
	protected:
		//parent class
		std::shared_ptr<plotobj> m_parent;
		std::string m_key;
	private:

	public:
			
	};


	using plotobj_ptr = std::shared_ptr<plt_shared::plotobj>;
	
	//map of plot objects
	class plotmap : public plotobj 
	{
	private:

		std::map<std::string, plotobj_ptr> m_plotmap; 
	public:	
		plotmap();
	};

	class plotary : public plotobj 
	{
	private:
		std::vector<plotobj_ptr> m_plotary;
	public:
		plotary();
	};

	
	
}
