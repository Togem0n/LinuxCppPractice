#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();

    if(pid > 0){
        printf("I'm parent process, pid: %d\n", getpid());
    }else if(pid == 0){
        printf("I'm child process before execl, pid: %d\n", getpid());

        execl("./hello", "hellonmsl", NULL);

        printf("I'm child process after execl, pid: %d\n", getpid());
    }

    // only parent process will run the for loop afterwards
    for (int i = 0; i < 3; i++)
    {
        printf("I'm parent process, pid: %d\n", getpid());
    }
}