#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <errno.h>
#include "ls.h"
#include <unistd.h>
/*
print_results function should be implemented with the new approach
start from line 46
*/
char options[] = {'a','l','f','h','d'};
BOOL flags[]={FALSE,FALSE,FALSE,FALSE,FALSE};
int main(int argc ,char **argv)
{
    DIR *directory;
    char* buffer = NULL;
    check_options(argc, argv);
    struct dirent *files;
    int files_number = 0;
    if(buffer == NULL)
    {
        directory = opendir(".");
    }
    else
    {
        directory = opendir(buffer);
        chdir(buffer);
    }
    /*the opendir function opens a directory stream related to the directory 
    name and returns a pointer to the directory stream 
    the stream is positioned at the first entry in the directory*/
    if(directory == NULL)
    {
        fprintf(stderr,"directory error: %s\n",strerror(errno));
        return 0;
    }
    while((files = readdir(directory)))
    {
        /*readdir function returns a pointer to a dirent strucTRUE representing 
          the next directory entry in the directory stream pointed to by 
         directory pointer.*/
        files_number ++;
        //struct stat fileStat;
        //print_results((files->d_name), fileStat , a,  f,  l,  lh);

    }
    
    printf("\n");
    // new_check_options(argc,argv);
    closedir(directory);
    return 0;
}

void check_options(int argc,char**argv)
{
for (int i = 1; i<argc; i++) {
    for(int j=0 ;j<OPTIONS_LENGTH ;j++)
    {
        if (contains_char(argv[i], options[j])) {
            flags[j]= TRUE;
        }
    }
}
for (int i =0; i<OPTIONS_LENGTH ;i++) {
        printf("%d\t",flags[i]);
    }
    printf("\n");
}

void print_results(char*file_name,struct stat fileStat )
{
    /*
    if(a==TRUE)
    {
        //if the flag is TRUE show all file names including hidden ones
        print_file_name(file_name);
    }
    else if(l==TRUE)
    {
        print_permissions(file_name ,fileStat);
    } 
    else if(f==TRUE)
    {

    }
    else if(lh == TRUE)
    {

    }
    else if (a == FALSE)
    {
        if(check_if_hidden(file_name))return; //checking if the file is hidden 
        else print_file_name(file_name);
    }
    else
    {
        print_file_name(file_name);
    }*/
}
void print_permissions(char *file_name , struct stat fileStat)
{
    if(stat(file_name, &fileStat) < 0)    
        {
            fprintf(stderr,"failure accessing file stat : %s\n",strerror(errno));
            exit(1);
        }
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\t%s \t",file_name);
    printf("\n"); 
    return ;
}

void print_file_name(char *file_name)
{
    printf("%s\t",file_name);
}

int check_if_hidden(char *file_name)
{
    return file_name[0] == '.';
}

BOOL contains_char(char*str , char target)
{
    for(int i =0 ; i<strlen(str);i++)
    {
        if(str[i]==target)
        return TRUE;
    }
    return FALSE;
}