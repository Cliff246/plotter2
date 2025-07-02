#pragma once

#include "dataholder.hpp"

namespace datter
{
	namespace dataholder
	{	
		class datahold_string : public ::datter::datahold
		{
		private:
			std::string string;
			bool is_utf8;
			
		public:
			std::string get_type() const override;
			std::vector<string_pair> get_args_info() const override;
			size_t get_nargs() override; 
			~datahold_string() override;
			std::string get_arg(size_t index) override; 
			
			std::string get_string();
			void set_string(std::string str);
		};
	}
}
