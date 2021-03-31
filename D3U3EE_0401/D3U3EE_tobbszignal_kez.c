#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void Megszakitas(int jel);
void kilepes(int jel);

unsigned int Megszakitasok = 0;

int main(void)
{
    if (signal(SIGINT, Megszakitas) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) SIGINT jelre!\n");
        return 0;
    }

    if (signal(SIGQUIT, kilepes) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) SIGQUIT jelre!\n");
        return 0;
    }

    while(Megszakitasok < 2)
    {
        printf("Varakozas a jelre...\n");
        sleep(1);
    }

    printf("Megvan a masodik SIGINT jel!");
    return 0;
}

void Megszakitas(int jel)
{
    printf("SIGINT signal: %d\n", jel);
    Megszakitasok++;
}

void kilepes(int jel)
{
    printf("SIGQUIT signal: %d\n", jel);
}
