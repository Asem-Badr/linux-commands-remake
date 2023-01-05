#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


int main(void)

{
    DIR *directory;
    struct dirent *files;
    int files_number = 0;
    directory =opendir(".");
    if(directory == NULL)
    {
        printf("unable to read this directory ");
        return 0;
    }
    while(files = readdir(directory))
    {
        files_number ++;
        printf("%s \n",files->d_name);
    }

    closedir(directory);
    return 0;
}
