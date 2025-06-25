#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>
#include <iostream>
#include "message.hpp"
#include <iostream>
#include <string>

int main() 
{
	
    std::string line;
    while (std::getline(std::cin, line)) 
	{
        std::cout << "[child] Received: " << line << std::endl;
        if (line == "exit") break;
    }
    return 0;
}
