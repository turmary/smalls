#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#define KEY	1234
#define TEXT_SIZE 48

struct msgbuffer {
	long mtype;
	char mtext[TEXT_SIZE];
}msgp;

int main() {
	int msgid;

	msgid = msgget(KEY, IPC_CREAT | 0600);
	printf("IPC_CREAT = %d\n", IPC_CREAT);
	if (fork() == 0) {
		sleep(3);
		msgp.mtype = 1;
		strcpy(msgp.mtext, "Hi! I am child process!\n");
		msgsnd (msgid, &msgp, TEXT_SIZE, 0);
		return 0;
	} else {
		msgrcv(msgid, &msgp, TEXT_SIZE, 0, 0);
		printf("parent receive mtext: %s\n", msgp.mtext);
		msgctl(msgid, IPC_RMID, NULL);
	}
	return 0;
}
