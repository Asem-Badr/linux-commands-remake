#include "helper.h"
#include <stdio.h> 

int main(int argc , char **argv)
{
    char **buffer ;
    buffer = many_args(argc,argv);
    for(int i=1; i<argc; i++)
    {
    printf("%s ",buffer[i]);
    }
    printf("\n");
    return 0;
}