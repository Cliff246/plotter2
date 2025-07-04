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
	listener childlistener(argc, argv);
	childlistener.start();
	childlistener.update();


}
