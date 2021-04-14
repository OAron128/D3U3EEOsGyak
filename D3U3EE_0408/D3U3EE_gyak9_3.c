#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


//int kill(pid_t pid, int sig);
void AlarmKezelo(int sig);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Hasznalat: ./D3U3EE_gyak9_3 PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    kill(pid, SIGALRM);
    
 if (signal(SIGALRM, AlarmKezelo) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) \"SIGALRM\" jelre!\n");
        return 1;
    }

    pause();
    return 0;
}

void AlarmKezelo(int sig)
{
    printf("D3U3EE\n Mostantol nem blokkolodok!\n");
    exit(1);
}
