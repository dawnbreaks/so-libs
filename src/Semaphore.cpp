#include "Semaphore.h"

Semaphore::Semaphore(string pathname, int proj_id, int nsem, int semflg) {
    key_t key;
    if ((key = ftok(pathname.c_str(), proj_id)) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((id = semget(key, nsem, semflg)) == -1) {
        perror("shmget");
        exit(2);
    }
}

void Semaphore::init(int sem_num, int value) {
    semctl(id, sem_num, SETVAL, value);
}

void Semaphore::wait(int sem_num, int semflg=0) {
    struct sembuf buf[1];
    buf[0].sem_num = sem_num;
    buf[0].sem_op = -1;
    buf[0].sem_flg = semflg;
    semop(id, buf, 1);
}

void Semaphore::signal(int sem_num, int semflg=0) {
    struct sembuf buf[1];
    buf[0].sem_num = sem_num;
    buf[0].sem_op = 1;
    buf[0].sem_flg = semflg;
    semop(id, buf, 1);
}

int Semaphore::getval(int sem_num) {
   union semun arg;
   semctl(id, sem_num, GETVAL, arg);
   return arg.val;
}

void Semaphore::remove() {
    semctl(id, IPC_RMID, NULL);
}

