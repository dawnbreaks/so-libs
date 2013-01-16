#include "FIFO.h"

FIFO::FIFO(string _path, mode_t _mode=0644) : 
    path(_path), mode(_mode), fd(0) {  

    if (mkfifo(path.c_str(), mode) == -1) {
        perror("mkfifo");
        exit(1);
    }     
}

FIFO::~FIFO() {
    if (fd) {
        close();
    }
}

void FIFO::remove() {
    if(unlink(path.c_str()) == -1) {
        perror("unlink");
        exit(2);
    }
}

void FIFO::open(int flags) {
    if ((fd = ::open(path.c_str(), flags)) == -1) {
        perror("open");
        exit(3);
    }
}

void FIFO::close() {
    if (::close(fd) == -1) {
        perror("close");
        exit(4);
    }
    fd = 0;
}

void FIFO::write(string data, int n) {
    if (::write(fd, data.c_str(), n) == -1) {
        perror("write");
        exit(5);
    }
}

string FIFO::read(int n) {
    char *data = new char[n];
    if (::read(fd, data, n) == -1) {
        perror("read");
        exit(6);
    }
    return (string) data;
}

