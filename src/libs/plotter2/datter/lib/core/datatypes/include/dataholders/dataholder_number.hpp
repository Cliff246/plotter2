#pragma once

#include "dataholder.hpp"

namespace datter
{
	namespace dataholder
	{	
		class datahold_number : public datahold
		{
		private:
			double number;
		public:
			std::string get_type() const override;
			std::vector<string_pair> get_args_info() const override;
			size_t get_nargs() override; 
			~datahold_number() override;
			std::string get_arg(size_t index) override; 
			
			double get_number();
			void set_number(double number);
		};
	}
}
