#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    // fork is used to create a child process.

    pid_t pid = fork();

    // on success, child's pid is returned to pid in parent process
    // and 0 is returned to pid in child process

    if(pid > 0){
        wait(NULL); // block the process to continue until one of its child exit;
        printf("I'm the parent process, my_pid: %d, parent_pid: %d\n", getpid(), getppid());
    }else if(pid == 0){
        printf("I'm the child process, my_pid: %d, parent_pid: %d\n", getpid(), getppid());
    }else{
        printf("create fail");
        return -1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("i: %d\n", i);
    }
    
    return 0;
}