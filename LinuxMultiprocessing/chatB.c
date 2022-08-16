#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int ret = access("fifo1", F_OK);
    if(ret == -1){
        printf("pipe1 doesnt exist\n");
        ret = mkfifo("fifo1", 0664);
        if(ret == -1){
            perror("mkfifo");
            exit(0);
        }
    }


    ret = access("fifo2", F_OK);
    if(ret == -1){
        printf("pipe2 doesnt exist\n");
        ret = mkfifo("fifo2", 0664);
        if(ret == -1){
            perror("mkfifo");
            exit(0);
        }
    }

    int fdr = open("fifo1", O_RDONLY);
    if(fdr == -1){
        perror("open");
        exit(0);
    }
    printf("open fifo1 successfully, waiting for reading data\n");

    int fdw = open("fifo2", O_WRONLY);
    if(fdw == -1){
        perror("open");
        exit(0);
    }
    printf("open fifo2 successfully, waiting for writing data\n");

    char buf[128];

    while(1){

        memset(buf, 0, 128);
        ret = read(fdr, buf, 128);
        if(ret <= 0){
            perror("read");
            break;
        }
        printf("buf?: %s\n", buf);

        memset(buf, 0, 128);
        fgets(buf, 128, stdin);
        
        ret = write(fdw, buf, strlen(buf));
        if(ret == -1){
            perror("write");
            exit(0);
        }
    }

    close(fdw);
    close(fdr);

    return 0;

}