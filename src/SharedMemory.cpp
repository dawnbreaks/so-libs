#include "SharedMemory.h"

SharedMemory::SharedMemory(string pathname, int proj_id, size_t size, int shmflg, int shmatflg, const void *shmaddr=NULL) {
    key_t key;
    if ((key = ftok(pathname.c_str(), proj_id)) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((id = shmget(key, size, shmflg)) == -1) {
        perror("shmget");
        exit(2);
    }

    ptr = shmat(id, shmaddr, shmatflg);
}

void* SharedMemory::attach(const void *shmaddr, int shmflg) {
    ptr = shmat(id, shmaddr, shmflg);
}

void SharedMemory::remove() {
    shmctl(id, IPC_RMID, NULL);
}

void* SharedMemory::get() {
    return ptr;
}
