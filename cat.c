#include "helper.h"
#include <stdio.h> 


int main(int argc , char **argv)
{
    FILE * file ;
    char buffer[buffer_size];
    file = fopen(one_arg(argc,argv),"r");
    while (fgets(buffer,buffer_size,file))
    {
        printf("%s ",buffer);
    }

    fclose(file);
    
    return 0;
}