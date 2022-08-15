#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){

    struct stat statbuf;

    int ret = stat("./test.txt", &stat);

    if(ret == -1){
        perror("NO SUCH FILE TO SHOW STATUS");
        return -1;
    }

    printf("size: %ld\n", statbuf.st_size);
    
    return 0;
}
