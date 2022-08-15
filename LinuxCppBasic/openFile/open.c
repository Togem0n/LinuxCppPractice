#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){

   int fd = open("a.txt", O_RDONLY);  
   
   if(fd == -1){
        perror("NO FILE WARNING");
   }

   close(fd);

   return 0;
}