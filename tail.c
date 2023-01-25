#include <stdio.h>
#include "helper.h"

int main(int argc, char **argv)
{
    FILE * file ;
    char buffer[buffer_size];
    file = fopen(one_arg(argc,argv),"r");
    fseek(file,0,SEEK_END);
    //for(int i = 10 ; i>0 ; i--)
    {
        fgets(buffer,buffer_size,file);
        
    }
    printf("%ld",ftell(file));
    fclose(file);

    return 0;
}