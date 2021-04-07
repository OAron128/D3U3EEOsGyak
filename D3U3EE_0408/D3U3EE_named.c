#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    pid_t child;
    int fd;

    if((mkfifo("D3U3EE", S_IRUSR | S_IWUSR)) < 0)
	{
        printf("Nem sikerult a FIFO\n");
        exit(1);
	}

    if((child = fork()) < 0){
        printf("Fork processz nem jó!\n");
        exit(1);
    }
	else
	{
		printf("Gyerek processz működik!\n\n");
	}
	
   
    if(!child){
        char *uzenet = "Oravecz Aron";
		
		
        if((fd = open("D3U3EE", O_WRONLY)) < 0){
            printf("Fifo nem megfelelő gyerek szerint\n");
            exit(1);
			
			
        } else {
			
            printf("Íras folyamatban...\n");
            write(fd, uzenet, strlen(uzenet));
			
        }
        printf("Gyerek processz befejezve\n");
    }
	
    
    if(child){
        char buf[1024];
        if((fd = open("D3U3EE", O_RDONLY)) <0 ){
			
            printf("FIFO failed!\n");
            exit(1);
			
        } else {
            read(fd, buf, sizeof(buf));
            printf("Adat: %s.\n", buf);
        }
        if((unlink("D3U3EE")) < 0 || (close(fd)) < 0){
			
            printf(" sikertelen FIFO torles!");
			
        } else {
			
            printf("kilepes\n");
        }
	}
    

    return 0;

}
