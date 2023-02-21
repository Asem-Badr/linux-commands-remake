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
// char options[] = {'a','l'};

int main(int argc, char **argv)
{
    DIR *directory;
    int a = 0, f = 0, l = 0, lh = 0; // options flags
    char *buffer = NULL;
    check_options(&a, &f, &l, &lh, argc, argv, &buffer);
    struct dirent *files;
    int files_number = 0;
    if (buffer == NULL)
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
    if (directory == NULL)
    {
        fprintf(stderr, "directory error: %s\n", strerror(errno));
        return 0;
    }
    while ((files = readdir(directory)))
    {
        /*readdir function returns a pointer to a dirent strucTRUE representing
          the next directory entry in the directory stream pointed to by
         directory pointer.*/
        files_number++;
        // this is added so as not to show . .. directories and hidden ones
        // if(files->d_name [0]=='.')continue;
        // printf("%s \t",files->d_name);
        struct stat fileStat;
        print_results((files->d_name), fileStat, a, f, l, lh);
    }

    printf("\n");
    closedir(directory);
    return 0;
}

void check_options(int *a, int *f, int *l, int *lh, int argc, char **argv, char **buffer)
{
    for (int i = 1; i < argc; i++)
    {
        if (!compareTwoString(argv[i], "-a"))
            *a = TRUE;
        else if (!compareTwoString(argv[i], "-f"))
            *f = TRUE;
        else if (!compareTwoString(argv[i], "-l"))
            *l = TRUE;
        else if (!compareTwoString(argv[i], "-lh"))
            *lh = TRUE;
        else if ((argv[i][0] != '-') && (argv[i][0] != '.')) // not a flag nor . then it's a directory
        {
            *buffer = argv[i];
        }
        else
        {
            printf("unknown option\n");
            exit(1);
        }
    }
    return;
}

void print_results(char *file_name, struct stat fileStat, int a, int f, int l, int lh)
{
    // printf("\n%d\n%s\n",l,file_name);

    if (l == TRUE)
    {
        if (a == TRUE)
        {
            // if the flag is TRUE show all file names including hidden ones
            print_permissions(file_name, fileStat);
        }
        else if (a == FALSE)
        {
            if (check_if_hidden(file_name))
                return; // checking if the file is hidden
            else
                print_permissions(file_name, fileStat);
        }
        return;
    }

    if (a == TRUE)
    {
        // if the flag is TRUE show all file names including hidden ones
        print_file_name(file_name);
    }
    else if (a == FALSE)
    {
        if (check_if_hidden(file_name))
            return; // checking if the file is hidden
        else
            print_file_name(file_name);
    }
}
void print_permissions(char *file_name, struct stat fileStat)
{
    if (stat(file_name, &fileStat) < 0)
    {
        fprintf(stderr, "failure accessing file stat : %s\n", strerror(errno));
        exit(1);
    }
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\t%s \t", file_name);
    printf("\n");
    return;
}

void print_file_name(char *file_name)
{
    printf("%s\t", file_name);
}

int check_if_hidden(char *file_name)
{
    return file_name[0] == '.';
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
    if (*a != '\0' || *b != '\0')
        return 1;
    if (flag == 0)
        return 0;
    else
        return 1;
}