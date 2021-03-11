#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int i=0;


    pid_t valtozo=fork();
    if(valtozo==0){
        printf("---Gyermek processz---\n");

    do
    {

    printf("\n\n tanuló: Oravecz Áron\n Neptunkód:D3U3EE\n");
    i++;    
            
    }while(i<5);

    exit(127);
}
 else{
    waitpid(valtozo,0,0);



    printf("---Szülő processz---\n A processz befejezte a futását!\n");
}


return 0;
}
