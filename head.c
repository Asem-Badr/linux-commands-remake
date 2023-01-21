#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "helper.h"


int main(int argc , char **argv)
{
    FILE * file ;
    char buffer[buffer_size];
    file = fopen(one_arg(argc,argv),"r");
    for(int i = 0 ; i<10 ; i++)
    {
        fgets(buffer,buffer_size,file);
        printf("%s",buffer);
    }

    fclose(file);
    
    return 0;
}
