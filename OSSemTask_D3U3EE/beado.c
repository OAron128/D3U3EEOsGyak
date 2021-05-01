#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int vissza;
    char buffer;

    if (argc == 1)
    {
        fprintf(stderr, "Használat: %s üzenet\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 2 csővezeték:
    // - szulo_fds: Amit a szülő használ hogy a gyereknek írjon
    // - gyerek_fds: Amit a gyerek használ hogy a szülőnek írjon
    int szulo_fds[2], gyerek_fds[2];

    // olvasás:[0] - írás:[1]
    if (pipe(szulo_fds) != 0 || pipe(gyerek_fds) != 0)
    {
        printf("Csövek létrehozása sikertelen!\n");
        return EXIT_FAILURE;
    }

    // Gyerek processz forkolás
    int child = fork();

    if (child < 0)
    {
        printf("Sikertelen forkolás!\n");
        return EXIT_FAILURE;
    }
    else if (child == 0)
    {

        close(gyerek_fds[0]);    
        close(szulo_fds[1]);

        // Olvasás szülő csővezetékből
        char szulotol[100];
        int n = read(szulo_fds[0], szulotol, sizeof(szulotol) - 1);
        szulotol[n] = '\0';
        printf("GYEREK - PID = %d: Beolvastam a szülőtől: '%s'\n", (int)getpid(), szulotol);

        close(szulo_fds[0]);

        // Amit olvasott most beírjuk
        strcat(szulotol, " (hozzáadva)");

        write(gyerek_fds[1], szulotol, strlen(szulotol));
        close(gyerek_fds[1]);
        printf("GYEREK - PID = %d: Írás a csővezetékre: '%s'\n", (int)getpid(), szulotol);
        
    }
    else
    {
        // Lezárom a csővezetékeket
        close(szulo_fds[0]);
        close(gyerek_fds[1]);

        // Terminálból beolvasott szöveg írása a szülő vezetékbe hogy a gyerek kiolvassa
        printf("SZÜLŐ - PID = %d: Írás a csővezetékre: '%s'\n\n", (int)getpid(), argv[1]);
        
        
        vissza = write(szulo_fds[1], argv[1], strlen(argv[1]));
        close(szulo_fds[1]);
		
		
        // Gyerek csővezetékből olvasás
        char gyerektol[100];
        int n = read(gyerek_fds[0], gyerektol, sizeof(gyerektol) - 1);
        gyerektol[n] = '\0';

        printf("A write() %d byteot írt.\n\n", vissza);

        close(gyerek_fds[0]);
        printf("SZÜLŐ - PID = %d: Csővezetékről olvasott: - '%s'\n", (int)getpid(), gyerektol);
    }
    return 0;
}
