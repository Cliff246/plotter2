#pragma once
#include <vector>
#include <string>
#include <memory>
#include "utils.hpp"

namespace datter
{
	using string_pair = std::pair<std::string, std::string>;
	class datahold
	{
	protected:
		bool m_held = false;
	public:
		virtual ~datahold() {};
		//get the type of this datahold
		virtual std::string get_type() const = 0;
		//gets arg information
		//item1 in pair is the return type,
		//item2 in pair is the helper
		virtual std::vector<string_pair> get_args_info() const = 0;
		//gets the amout of args
		virtual size_t get_nargs() = 0;
		//gets the arg at postion 'index'
		//
		virtual std::string get_arg(size_t index) = 0; 

		bool check_if_holding() const;

	};
	using datahold_ptr = std::shared_ptr<datahold>; 
	
	constexpr char integer_type[] = "int";
	constexpr char string_type[] = "str";
	constexpr char array_type[] = "ary";
	constexpr char float_type[] = "num";
	constexpr char map_type[] = "map";

}
