#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12  // Kulcs

int semID;
int nsems;
int r; 
int cmd;
int semflag;

struct sembuf sembuf, *sop;
union semun arg;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main()
{
	semflag = 00666 | IPC_CREAT;
	nsems = 1;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ) {
        perror("Probléma/hiba!\n"); 
        return 0;
    }
	else 
        printf("ID avagy azonosító: %d\n",semID);
	r = semctl(semID,0, cmd, NULL);
	cmd = GETVAL;
	printf("A kiolvasott értéke: %d\n",r);
    return 0;

}
