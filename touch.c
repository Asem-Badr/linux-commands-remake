#include "helper.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc , char **argv)
{
    FILE *file = fopen(one_arg(argc,argv),"w+");
    fclose(file);
    return 0;
}