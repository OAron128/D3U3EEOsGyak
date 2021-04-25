#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 13

struct shmid_ds shmid_ds, *buf;

int main()
{
  int schmid;
  int flag;
  int vissza;
  int size = 512;
  key_t key;


  buf = &shmid_ds;
  key = SHMKEY;
  flag = 0;

  if((schmid = shmget(key, size, flag)) < 0)
  {
     perror("\nA shmget sikertelen!");
     return -1;
  }
    vissza = shmctl(schmid, IPC_STAT, buf);
    printf("\n meret: %ld", buf->shm_segsz);
    printf("\n pid: %d\n", buf->shm_lpid);


  return 0;
}
