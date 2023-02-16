#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

char* one_arg(int argc , char **argv)
{
    if(argc == 2 )
    {
        //the following line is used for depugging 
        //printf("%s\n",argv[1]);
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
char** many_args(int argc , char **argv)
{
    if(argc >= 2)
    {
        return argv;
    }
    else
    {
        return NULL;
    }
}
void saferFree(void **pp)
{
    if(pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}