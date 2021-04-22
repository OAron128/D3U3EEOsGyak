#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#define MSGKEY 654321L

int main()
{
	int index;
    int msgflg;
    int vissza;

	key_t kulcs;
	kulcs = MSGKEY;


	msgflg = 00666 | IPC_CREAT;
	index = msgget(kulcs, msgflg);
	

	vissza = msgctl(index, IPC_RMID, NULL);	            // Törli az üzenetet
	printf("Visszatérési érték: %d\n", vissza);

	return 0;
}
