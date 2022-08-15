#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getFileNum(const char * path);

// loop through directory and get file number under that directory.
int main(int argc, char * argv[]){

    if(argc < 2){
        printf("%s path\n", argv[0]);
        return -1;
    }

    int fileNum = getFileNum(argv[1]);

    printf("file num is : %d\n", fileNum);

    return 0;
}

int getFileNum(const char * path){
    
    DIR * dir = opendir(path);

    if(dir == NULL){
        perror("NO DIR TO OPEN");
        exit(0);
    }

    struct dirent *ptr;

    int total = 0;

    while((ptr = readdir(dir)) != NULL){

        char * dname = ptr->d_name;

        if(strcmp(dname, ".") == 0 || strcmp(dname, "..") == 0){
            continue;
        }

        if(ptr->d_type == DT_DIR){
            
            char newPath[256];
            sprintf(newPath, "%s/%s", path, dname);
            total += getFileNum(newPath);
        }

        if(ptr->d_type == DT_REG){
            total++;
        }
    }

    closedir(dir);
    return total;
}