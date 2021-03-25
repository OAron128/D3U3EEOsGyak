#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



int main()
{
    int FILE;
    int back;
    char buffer[50];

    buffer[0] = 0;

    FILE = open("D3U3EE.txt", O_RDWR);

    if (FILE == -1) {
        perror("Fajl megnyitas open() --> hiba! \n");
        exit(-1);
    }
    else{
    
    }

    back = read(FILE, buffer, 50);
    printf("%d byteot olvasott be a read().\n\n", back);
    strcpy(buffer, "D3U3EE");


    back = lseek(FILE, 0, SEEK_SET);
    printf("A lseek() beallitva a -->  %d. helyen ", back);

    back = write(FILE, buffer, 6);
    printf(" %d byteot irt ki a write()...: %s\n\n\n", back, buffer);
    strcpy(buffer, "D3U3EE");
    
    close(FILE);

    return 0;
}
