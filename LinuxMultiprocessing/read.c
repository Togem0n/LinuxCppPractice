#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int fd = open("test", O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(0);
    }

    while(1){
        char buf[1024] = {0};
        int len = read(fd, buf, sizeof(buf));

        if(len == 0){
            printf("lose connect\n");
            break;
        }

        printf("recv buf: %s\n", buf);
    }

    return 0;
}