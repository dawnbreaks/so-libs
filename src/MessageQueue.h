#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

using std::string;

struct message {
    long mtype;
    char *mtext;
};

class MessageQueue {
private:
    int id;
public:
    MessageQueue(string pathname, int proj_id, int msgflg);

    void send(long mtype, char *message, int msgflg);
    ssize_t receive(long mtype, struct message *msgp, size_t msgsz, int msgflg);
    void remove();
};
