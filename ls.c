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
    /*the opendir function opens a directory stream related to the directory 
    name and returns a pointer to the directory stream 
    the stream is positioned at the first entry in the directory*/
    if(directory == NULL)
    {
        printf("unable to read this directory ");
        return 0;
    }
    while(files = readdir(directory))
    {
        /*readdir function returns a pointer to a dirent structrue representing 
          the next directory entry in the directory stream pointed to by 
         directory pointer.*/
        files_number ++;
        //this is added so as not to show . .. directories and hidden ones
        if(files->d_name [0]=='.')continue; 
        printf("%s \t",files->d_name);
    }
    printf("\n");
    closedir(directory);
    return 0;
}
