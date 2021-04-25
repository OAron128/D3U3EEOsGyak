#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#define SHMKEY 13

int main()
{
  int shmid;
  int flag;
  int vissza;
  int choose;
  int size = 256;
  key_t key;

  key = SHMKEY;
  flag = 0;

  if((shmid = shmget(key, size, flag)) < 0)
  {
     flag = 00666 | IPC_CREAT;
     if((shmid = shmget(key, size, flag)) < 0)
     {
        perror("\nA shmget sikertelen!");
        return -1;
     }
  }
  printf("\nAz azonosító : %d\n", shmid);

	return 0;
}
