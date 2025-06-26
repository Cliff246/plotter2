#pragma once
#include "dataholder.hpp"
#include <string>
#include <vector>

namespace plt_shared
{
	namespace dataholder
	{	
		class datahold_array : public datahold
		{
		private:
			std::vector<datahold_ptr> m_array;
		public:
			std::string get_type() const override;
			std::vector<plt_shared::string_pair> get_args_info() const override;
			size_t get_nargs() override; 
			~datahold_array() override;

			std::string get_arg(size_t index) override; 

			std::vector<datahold_ptr> get_array();
			void set_array(std::vector<datahold_ptr> &array);
			datahold_ptr get_elemenet(size_t index);
			void set_element(size_t inddex, datahold_ptr ptr);
			size_t get_length() const;

		};
	}
}

