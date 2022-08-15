#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){

    struct stat statbuf;

    // stat is used to get hard link file status
    // if you want to get soft link file status
    // for example, to get B which is soft link version of A
    // you use lstat(B...) otherwise you would get status of A

    int ret = stat("./test.txt", &statbuf);

    if(ret == -1){
        perror("NO SUCH FILE TO SHOW STATUS");
    }

    printf("size: %ld\n", statbuf.st_size);
    
    return 0;
}
