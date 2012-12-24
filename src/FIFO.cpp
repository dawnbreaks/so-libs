#include "FIFO.h"

/*
 * TODO konwersja string na char* ...?
 */

FIFO::FIFO(string _path, int _flags, mode_t _mode=0644) : 
    path(_path), flags(_flags), mode(_mode), fd(0) {       
}

FIFO::~FIFO() {
    if (fd) {
        close();
    }
}

void FIFO::create() {
    if (mkfifo(path.c_str(), mode) == -1) {
        perror("mkfifo");
        exit(1);
    }
}

void FIFO::remove() {
    if(unlink(path.c_str()) == -1) {
        perror("unlink");
        exit(2);
    }
}

void FIFO::open() {
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
    return data;
}

int main() {
 
    if (fork() == 0) {
        sleep(2);
        FIFO fifo("file", O_RDONLY);
        fifo.open();
        cout << fifo.read(6) << endl;
        fifo.close();
        fifo.remove();
    } else {
        FIFO fifo("file", O_WRONLY);
        fifo.create();
        fifo.open();
        fifo.write("Hello", 6);
        fifo.close();
    }
    return 0;
}

