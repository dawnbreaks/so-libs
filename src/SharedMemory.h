#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

using std::string;

class SharedMemory {
private:
    int id;
    void *ptr;
public:
    SharedMemory(string pathname, int proj_id, size_t size, int shmflg, int shmatflg, const void *shmaddr);
    void* attach(const void *shmaddr, int shmflg);
    void remove();
    void* get();
};
