#pragma once 

#include "dataholder.hpp"

namespace datter
{
	namespace dataholder
	{	
		class datahold_integer : public datahold
		{
		private:
			int64_t integer;
		public:
			std::string get_type() const override;
			std::vector<string_pair> get_args_info() const override;
			size_t get_nargs() override; 
			~datahold_integer() override;
			std::string get_arg(size_t index) override; 
			
			int64_t get_integer();
			void set_integer(int64_t integer);
		};
	}
}
