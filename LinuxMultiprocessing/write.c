#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    // pipe is also a kind of file

    int ret = access("test", F_OK);
    if(ret == -1){
        ret = mkfifo("test", 0664);

        if(ret == -1){
            perror("mkfifo");
            exit(0);
        }
    }

    int fd = open("test", O_WRONLY);

    if(fd == -1){
        perror("open");
        exit(0);
    }

    for (int i = 0; i < 10; i++)
    {
        char buf[1024];
        sprintf(buf, "hello %d\n", i);   // writing data to the buffer
        printf("write data: %s\n", buf); // print it out
        write(fd, buf, strlen(buf));
        sleep(1);
    }
    
    close(fd);

    return 0;
}