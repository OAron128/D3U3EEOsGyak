#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int pipe, vissza;
	char tomb[32];

	//O_RDWR / megnyitja a proba txt-t irásra és olvasásra egyaránt.

	pipe=open("proba.txt",O_RDWR);  ///pipe egyenlő lesz a txt megnyitással
	if (pipe == -1) {
	    perror("open() hiba!");   ///ha nem sikerül megnyitni vagyis hivás kiirja ezt
	    exit(-1);
	}
	vissza=lseek(pipe,0,SEEK_SET);    //lseek(honnan kezdi el írni) hova teszi a kurzort
	vissza=read(pipe,tomb,32); // vissza: mennyi bájtot sikerült beolvasni
	printf("read() olvasott %d byteot, ami a kovetkezo: %s\n",vissza,tomb);
	close(pipe);
}
