#ifndef H_FIFO
#define H_FIFO

#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <cerrno>

using std::string;

class FIFO {
private:
    int fd;
    string path;
    mode_t mode;
public:
    FIFO(string _path, mode_t mode);    
    ~FIFO();    
    
    void remove();

    void open(int flags);
    void close();

    void write(string data, int n);
    string read(int n);
};

#endif
