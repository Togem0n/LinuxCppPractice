#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int pipefd[2];
    int ret = pipe(pipefd);

    if(ret == -1){
        perror("pipe");
        exit(0);
    }

    pid_t pid = fork();

    if(pid > 0){
        char buf[1024] = {0};
        while(1){
            int len = read(pipefd[0], buf, sizeof(buf));    
            printf("hello, I'm parent process receiving: \n%sfrom pid: %d\n", buf, getpid());
        }
    }else if(pid == 0){
        char * writeMsg = "hello, I'm child process and writing to the pipe\n";
        write(pipefd[1], writeMsg, strlen(writeMsg));
    }

    return 0;
}