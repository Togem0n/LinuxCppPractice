#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>

int main(){

    // check if the calling process can be accessed, read, write or excute.
    // F_OK, R_OK, W_OK, X_OK

    int flag = access("test.txt", F_OK);

    if(flag == -1){
        perror("NO SUCH FILE");
    }else{
        printf("FILE EXIST\n");
    }

    // chmod: change accessibility of file
    // chown: change owner of file
    // turncate: change file size. 
    // int truncate(const char *path, off_t length);
    // int ftruncate(int fd, off_t length);

    return 0;
}