#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#define MSGKEY 654321L

struct msgbuf1 {
	long tipus;
	char mtext[1024];
} rcvbuf, *szovegpont;	

struct msqid_ds ds, *buf;

int main()
{
	int index;		
    int tipus;
    int msgflg;	
	int vissza; 
    int meret;	

	key_t kulcs;		
	
	kulcs = MSGKEY;	
	msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

	index = msgget(kulcs, msgflg);    
 	if ( index == -1) {
                perror("\n Msgget sikertelen volt a rendszerhívás!");
                exit(-1);
        }
	printf("\n Üzenet ID: %d",index);

	szovegpont = &rcvbuf;		
	buf = &ds;		
    tipus = 0;
	meret = 20;				
	vissza = msgctl(index,IPC_STAT,buf); 
	printf("\nÜzenet száma: %ld\n",buf->msg_qnum);
	
	while (buf->msg_qnum) {		

	vissza = msgrcv(index,(struct msgbuf *)szovegpont, meret, tipus, msgflg);
	printf("\nVisszatérés: %d,A fogadott üzenet:%s\n",vissza, szovegpont->mtext);
	vissza = msgctl(index,IPC_STAT,buf);  
    }
	return 0;
}
