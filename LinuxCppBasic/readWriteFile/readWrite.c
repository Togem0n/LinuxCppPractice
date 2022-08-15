#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    /*
        open source file and check if exist
        open des file or create if doesnt exist

        create buffer in memory to store things we read from source file
        while loop to write in des file
    */
    int srcfd = open("./srcfile.txt", O_RDONLY);

    if(srcfd == -1){
        perror("OPEN");
        return -1;
    }

    int desfd = open("./desfile.txt", O_WRONLY | O_CREAT, 0664);

    char buf[1024] = {0};

    int len = read(srcfd, buf, sizeof(buf));

    while(len > 0){
        write(desfd, buf, len);
        len = read(srcfd, buf, sizeof(buf));
    }
    
    close(srcfd);
    close(desfd);

    return 0;
}