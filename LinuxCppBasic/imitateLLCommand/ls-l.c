#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>   
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char * argv[]){

    if(argc < 2){
        printf("%s filename\n", argv[0]);
        return -1;
    }

    struct stat st;
    
    stat(argv[1], &st);

    char * fileUser = getpwuid(st.st_uid)->pw_name;
    char * fileGroup = getgrgid(st.st_gid)->gr_name; 
    long int fileSize = st.st_size;
    char * time = ctime(&st.st_mtime);

    printf("%s %s %ld %s", fileUser, fileGroup, fileSize, time);
    return 0;
}