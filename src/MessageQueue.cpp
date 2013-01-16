#include "MessageQueue.h"

MessageQueue::MessageQueue(string pathname, int proj_id, int msgflg) {
    key_t key;
    if ((key = ftok(pathname.c_str(), proj_id)) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((id = msgget(key, msgflg)) == -1) {
        perror("msgget");
        exit(2);
    }
}

void MessageQueue::send(long mtype, char *message, int msgflg=0) {
    struct message msgp;
    msgp.mtype = mtype;

    size_t n = strlen(message)+1;
    msgp.mtext = new char[n];
    strncpy(msgp.mtext, message, n);
    
    if (msgsnd(id, (struct msgbuf*) &msgp, n, msgflg) == -1) {
        perror("msgsnd");
        exit(3);
    }
}

ssize_t MessageQueue::receive(long mtype, struct message *msgp, size_t msgsz, int msgflg=0) {
    msgp->mtext = new char[msgsz+1];

    ssize_t size;
    if ((size = msgrcv(id, (struct msgbuf*) msgp, msgsz, mtype, msgflg)) == -1) {
        perror("msgrcv");
        exit(4);
    }
    
    return size;
}

void MessageQueue::remove() {
    msgctl(id, IPC_RMID, NULL);
}
