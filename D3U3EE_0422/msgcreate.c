#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define SZOVEGKULCS 654321L

struct szovegbuf {		
	char sajatszoveg[1024];
    long entipus;
} sndbuf, *uzenetpont;		

int main()
{
    int msgflg;		
	int vissza, szovegmeret;		
	int index;		
	key_t kulcs;		

	
	kulcs = SZOVEGKULCS;
	msgflg = 00666 | IPC_CREAT;
	index = msgget( kulcs, msgflg);

 	if ( index == -1) {
       exit(-1);
       perror("Msgget nem volt sikeres a rendszerhívásban!");
    }
	uzenetpont = &sndbuf;
	uzenetpont->entipus = 1; 
  		
 	strcpy(uzenetpont->sajatszoveg,"Szia első üzenetem D3U3EE");
	szovegmeret = strlen(uzenetpont->sajatszoveg) + 1;	
    vissza = msgsnd(index,(struct szovegbuf *) uzenetpont, szovegmeret, msgflg);
	printf("\n Üzenet: %s", uzenetpont->sajatszoveg);



	strcpy(uzenetpont->sajatszoveg,"A másik üzenet pedig a Oravecz Aron");
	szovegmeret = strlen(uzenetpont->sajatszoveg) + 1;
	vissza = msgsnd(index,(struct szovegbuf *) uzenetpont, szovegmeret, msgflg);
	printf("\n Üzenet: %s \n", uzenetpont->sajatszoveg);

	return (0);
}
