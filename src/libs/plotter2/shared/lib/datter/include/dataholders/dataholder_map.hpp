#pragma once 

#include "dataholder.hpp"
#include <map>
namespace plt_shared
{
	namespace dataholder
	{	
		//holds map<string, datahold_ptr>
		class datahold_map : public datahold
		{
		private:
			std::map<std::string, datahold_ptr> m_map;
		public:
			std::string get_type() const override;
			std::vector<plt_shared::string_pair> get_args_info() const override;
			size_t get_nargs() override; 
			~datahold_map() override;
			std::string get_arg(size_t index) override; 
			
			std::map<std::string, datahold_ptr> get_map();
			void set_map(std::map<std::string, datahold_ptr> &map);
			

		};
	}
}
