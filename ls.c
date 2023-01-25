#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#define true 1
#define false 0
void check_options(int *a, int *f, int *la, int *lh, int *argc, char **argv);
int compareTwoString(char *a, char *b);
int main(int argc ,char **argv)

{
    DIR *directory;
    int a=0,f=0,la=0,lh=0;
    //check_options(&a ,&f ,&la, &lh, &argc ,argv);

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
    while((files = readdir(directory)))
    {
        /*readdir function returns a pointer to a dirent structrue representing 
          the next directory entry in the directory stream pointed to by 
         directory pointer.*/
        files_number ++;
        //this is added so as not to show . .. directories and hidden ones
        if(files->d_name [0]=='.')continue; 
        printf("%s \t",files->d_name);
    }
    //the following lines are for debugging purpose only
    printf("%d %d %d %d",a,f,la,lh);
    printf("%d",strcmp(argv[1],"f"));
    //************************************
    printf("\n");
    closedir(directory);
    return 0;
}

void check_options(int *a, int *f, int *la, int *lh, int *argc, char **argv)
{
    for(int i=0; i< *argc ;i++)
    {   
        if (!compareTwoString(argv[i],"a"))
        *a = 1;
        else if (!compareTwoString(argv[i],"f"))
        *f =true;
    }
    return;
}
int compareTwoString(char *a, char *b)
{
    int flag = 0;
    while (*a != '\0' && *b != '\0') // while loop
    {
        if (*a != *b)
        {
            flag = 1;
        }
        a++;
        b++;
    }
 if(*a!='\0'||*b!='\0')
       return 1;
    if (flag == 0)
        return 0;
    else
        return 1;
}
