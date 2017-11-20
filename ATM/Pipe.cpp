//
// Created by hspark on 17. 11. 17.
//

#include "Pipe.h"

Pipe::Pipe() {
    if (pipe(fd) == -1)
        throw std::string("pipe creation fails.");
}

int Pipe::getReadFD() {
    {
        return fd[0];
    }
}

int Pipe::getWriteFD() {

    return fd[1];

}