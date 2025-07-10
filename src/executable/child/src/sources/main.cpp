#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>
#include <iostream>
#include "message.hpp"
#include <iostream>
#include <string>
#include "listener.hpp"

using namespace p2child;



int main(int argc, char **argv) 
{
	
	//for some reason this bullshit has to happen
	py::scoped_interpreter guard {}; 

    // Redirect sys.stdout, sys.stderr, sys.stdin to dummy objects
    py::module sys = py::module::import("sys");
    sys.attr("stdin")  = py::module::import("io").attr("StringIO")();
    //sys.attr("stdout") = py::module::import("io").attr("StringIO")();
    sys.attr("stderr") = py::module::import("io").attr("StringIO")();

	py::gil_scoped_release release;
	
	listener childlistener(argc, argv);
	childlistener.start();
	childlistener.update();

}
