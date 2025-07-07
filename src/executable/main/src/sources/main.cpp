#include <iostream>
#include <Python.h>
#include <filesystem>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>

#include <spawn.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstring>


#include "parent.hpp"
#include "manifest.hpp"
#include <pybind11/embed.h>
#include "runtime.hpp"
#include "loggy.hpp"

namespace py = pybind11;
using namespace p2exe;

extern char **environ;

int main(int argc, char **argv) 
{
	//init loggy
	plt_shared::init_loggy();	
	//start up runtime
	runtime rt = runtime(argc, argv, environ);	
	//init runtime
	rt.init();
	//TODO the main entrance loop
	rt.update();
		
    return 0;
}
