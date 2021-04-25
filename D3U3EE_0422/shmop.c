#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#define SHMKEY 13

struct str {
 char text[1024-sizeof(int)];
 int lng;
} *segment;

int main()
{
  int shmid;
  int flag=0;
  int meret = 1024;
  key_t kulcs;
  kulcs = SHMKEY;
  flag = 0;

  if((shmid = shmget(kulcs, meret, flag)) < 0)
  {
     perror("\n Sikertelen volt az shmget!\n");
     exit(-1);
  }

  flag = 00666 | SHM_RND;
  segment = (struct str *)shmat(shmid, NULL, flag);

  if(segment == (void *) - 1)
  {
     perror("\nSikertelen!");
     return -1;
  }

  if(strlen(segment->text) > 0)
  {
     printf("\nA régi szöveg : %s", segment->text);
  }

   printf("\n Adja meg az új szöveget : ");
   scanf("%s", segment->text);
   printf("\núj szöveg : %s \n", segment->text);

   shmdt(segment);
   return 0;
}
