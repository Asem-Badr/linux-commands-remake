#include "helper.h"
#include <stdio.h>
#include <stdlib.h>

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