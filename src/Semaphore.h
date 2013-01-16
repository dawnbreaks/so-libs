#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

using std::string;

union semun {
    int              val;  
    struct semid_ds *buf;  
    unsigned short  *array;
    struct seminfo  *__buf;
};

class Semaphore {
private:
    int id;
public:
    Semaphore(string pathname, int proj_id, int nsem, int semflg);
    void remove();
    void init(int sem_num, int value);

    void wait(int sem_num, int semflg);
    void signal(int sem_num, int semflg);

    int getval(int sem_num);
};
