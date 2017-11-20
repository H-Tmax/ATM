#ifndef ATM_PIPE_H
#define ATM_PIPE_H
#ifdef _WIN32
#include <mingw.thread.h>
#include <fcntl.h>
#define pipe(fds) _pipe(fds,4096, _O_BINARY)
#endif

#include <unistd.h>
#include <string>
#include <iostream>


class Pipe {
public:
    Pipe();

    int getReadFD();

    int getWriteFD();

private:
    int fd[2];
};


#endif //ATM_PIPE_H
