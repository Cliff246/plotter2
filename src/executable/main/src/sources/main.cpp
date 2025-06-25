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

namespace py = pybind11;
extern char **environ;

int main() 
{
    int pipefd[2];
    if (pipe(pipefd) == -1) 
	{
        perror("pipe");
        return 1;
    }

    posix_spawn_file_actions_t actions;
    posix_spawn_file_actions_init(&actions);

    // Set child's stdin to read end of the pipe
    posix_spawn_file_actions_adddup2(&actions, pipefd[0], STDIN_FILENO);
    // Close the write end in the child
    posix_spawn_file_actions_addclose(&actions, pipefd[1]);

    pid_t pid;
    char *argv[] = {const_cast<char*>("./child"), nullptr};
    if (posix_spawn(&pid, "./child", &actions, nullptr, argv, environ) != 0) 
	{
        perror("posix_spawn");
        return 1;
    }

    // Parent process: close read end, write messages
    close(pipefd[0]);
    const char* messages[] = {"Hello from parent\n", "Second message\n", "exit\n"};
    for (auto msg : messages) 
	{
        write(pipefd[1], msg, strlen(msg));
        sleep(1);
    }
    close(pipefd[1]);

    int status;
    waitpid(pid, &status, 0);

    std::cout << "[parent] Done.\n";
    return 0;
}
