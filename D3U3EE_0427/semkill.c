#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x10

int semID;
int nsems;
int r;
int cmd;
int semflag;

struct sembuf sembuf, *sop;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main()
{
    int arg;
	nsems = 1;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ){
        perror("Probléma/hiba!\n"); 
        return 0;
    }
	else 
        printf("semID-nak az értéke: %d\n",semID);

	cmd = IPC_RMID;
	r = semctl(semID,0, cmd, arg);
	printf("Kill visszatérési értéke: %d\n",r);
    
    return 0;
}
