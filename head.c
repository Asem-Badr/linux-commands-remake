#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define buffer_size 1024

char* check_args(int argc , char **arcv);

int main(int argc , char **argv)
{
    FILE * file ;
    char buffer[buffer_size];
    file = fopen(check_args(argc,argv),"r");
    for(int i = 0 ; i<10 ; i++)
    {
        fgets(buffer,buffer_size,file);
        printf("%s",buffer);
    }

    fclose(file);
    
    return 0;
}


char* check_args(int argc , char **argv)
{
    if(argc == 2 )
    {
        printf("%s\n",argv[1]);
        return argv[1];
    }
    else if (argc >2 )
    {
        printf("too many args to process \n");
        exit(1);
    }else 
    {
        printf("expected one file to be supplied \n");
        exit(1);
    }
}