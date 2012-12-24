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

using namespace std;

class FIFO {
private:
    int fd;
    string path;
    int flags;
    mode_t mode;
public:
    FIFO(string _path, int _flags, mode_t _mode);    
    ~FIFO();    
   
    void create();
    void remove();

    void open();
    void close();

    void write(string data, int n);
    string read(int n);
};

#endif
