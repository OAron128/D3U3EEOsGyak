#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHMKEY 13


struct str {
    int lng;
    char text[1024-sizeof(int)];
} *segment;

int main()
{
  int vissza;
  int choose;
  int shmid;
  int flag;
  int size = 512;
  key_t key;

  key = SHMKEY;
  flag = 0;

  if((shmid = shmget(key, size, flag)) < 0)
  {
     flag = 00666 | IPC_CREAT;
     if((shmid = shmget(key, size, flag)) < 0)
     {
        perror("\nA shmget sikertelen volt!");
        return -1;
     }
  }

  printf("\nAz azonosító : %d\n", shmid);

  flag = 00666 | SHM_RND;
  segment = (struct str *)shmat(shmid, NULL, flag);

  if(segment == (void *) - 1)
  {
     perror("\nCsatlakozás sikertelen volt");
     return -1;
  }

  if(strlen(segment->text) > 0)
  {
     printf("\nA régi szöveg : %s", segment->text);
  }
    
  printf("\núj szöveget : ");
  scanf("%s", segment->text);
  printf("\nAz új szöveg: %s \n", segment->text);

  shmdt(segment);
  struct shmid_ds shmid_ds, *buf;
  buf = &shmid_ds;
  flag = 0;

  do {
    printf("A menü opciói:\n");
    printf("0. Státusz lekérdezése\n");
    printf("1.törlés a memóriából\n");
    scanf("%d", &choose);

  }while(choose != 0 && choose != 1);

  if(choose == 0){
    vissza = shmctl(shmid, IPC_STAT, buf);
    printf("\nMéret: %ld", buf->shm_segsz);
    printf("\nPid: %d\n", buf->shm_lpid);
  }
  else if(choose == 1){
    vissza = shmctl(shmid, IPC_RMID, NULL);
    printf("\nMegszüntetve a szegment\n");
  }

  exit(0);
}
