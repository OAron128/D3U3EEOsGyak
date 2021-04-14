#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void TerimalKezelo(int sig);

int main(void)
{
    if (signal(SIGKILL,TerimalKezelo) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) \"SIGKILL\" jelre!\n");
        return 0;
    }

    while(-1)
    {
        printf("Varakozas...\n");
        sleep(3);
    }

    return 0;
}

void TerimalKezelo(int sig){

    signal(sig, SIG_IGN);
    printf("signal értéke: %d...\n",sig);
}
