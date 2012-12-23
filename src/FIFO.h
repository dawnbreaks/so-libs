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

using namespace std;

class FIFO {
private:
    int fd;
    string pathName;
public:
    FIFO(string path, mode_t mode, int flags);    
    ~FIFO();    

    void write(string data, int n);
    string read(int n);
    void close();
    void remove();
};

#endif
