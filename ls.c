#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

#define true 1
#define false 0

void check_options(int *a, int *f, int *l, int *lh, int argc, char **argv,char**buffer);
int compareTwoString(char *a, char *b);
void print_results(char*file_name,struct stat fileStat ,int a, int f, int l, int lh);

int main(int argc ,char **argv)

{
    DIR *directory;
    struct stat fileStat;
    
    int a=0,f=0,l=0,lh=0;//options flags
    char* buffer = NULL;
    check_options(&a ,&f ,&l, &lh, argc ,argv ,&buffer);
    //printf("\n\n%s\n\n",buffer); for debugging purposes
    struct dirent *files;
    int files_number = 0;
    if(buffer == NULL)
    {
        directory = opendir(".");
    }
    else
    {
        directory = opendir(buffer);
    }
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
        //printf("%s \t",files->d_name);
        print_results((files->d_name), fileStat , a,  f,  l,  lh);

    }
    
    printf("\n");
    closedir(directory);
    return 0;
}

void check_options(int *a, int *f, int *l, int *lh, int argc, char **argv ,char**buffer)
{
    for(int i=1; i< argc ;i++)
    {   if (!compareTwoString(argv[i],"-a"))
        *a = true;
        else if (!compareTwoString(argv[i],"-f"))
        *f =true;
        else if (!compareTwoString(argv[i],"-l"))
        *l = true;
        else if (!compareTwoString(argv[i],"-lh"))
        *lh = true;
        else if ((argv[i][0] != '-')&&(argv[i][0] != '.'))//not a flag nor . then it's a directory
        {*buffer = argv[i];}
        else 
        {
        printf("unknown option");
        exit(1);
        }
    }
    return;
}
int compareTwoString(char *a, char *b)
{
    int flag = 0;
    while (*a != '\0' && *b != '\0') 
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

void print_results(char*file_name,struct stat fileStat ,int a, int f, int l, int lh)
{
    printf("\n%d\n%s\n",l,file_name);
    if(l==1)
    {
    if(stat(file_name, &fileStat) < 0)    
        exit(1);

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

    } 
    else 
    {
        printf("\t%s \t",file_name);
    }


}