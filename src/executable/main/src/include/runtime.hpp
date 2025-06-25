#pragma once


#include <vector>
#include <string>
#include "parent.hpp"
#include "childholder.hpp"

namespace p2exe
{
	




	class runtime
	{
	private:
		int arg_count;
		std::vector<std::string> arguments;

	public:
		runtime();
		runtime(int argv, char **argc);

		void update();
		~runtime();
	};

}
