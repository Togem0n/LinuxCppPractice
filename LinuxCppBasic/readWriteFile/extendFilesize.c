#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int fd = open("./fileToBeExtended.txt", O_RDWR);

    if(fd == -1){
        perror("NO SUCH FILE TO BE EXTENDED");
    }
    
    // lseek can be used to get location of fd
    // lseek can also be used to extend file size as example below

    lseek(fd, 130, SEEK_END); 

    write(fd, " ", 1);

    close(fd);

    return 0;
}