#include "FIFO.h"

FIFO::FIFO(string path, mode_t mode=0644, int flags=O_WRONLY) {
    if (mkfifo(path.c_str(), mode) == -1) {
        perror("mkfifo");
        exit(1);
    }

    if ((fd = open(path.c_str(), flags)) == -1) {
        perror("open");
        exit(1);
    }

    pathName = path;
}

FIFO::~FIFO() {
    ::close(fd);
    unlink(pathName.c_str());
}

void FIFO::write(string data, int n) {
    ::write(fd, data.c_str(), n);
}

string FIFO::read(int n) {
    char *data = new char[n];
    ::read(fd, data, n);
    return data;
}

void FIFO::close() {
    ::close(fd);
}

void FIFO::remove() {
    unlink(pathName.c_str());
}

int main() {
    FIFO fifo("plik", 0644, O_RDONLY|O_NONBLOCK);
    
    return 0;
}

