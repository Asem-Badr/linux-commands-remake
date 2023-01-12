#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *buf;
    buf=(char *)malloc(100*sizeof(char));
    getcwd(buf,100);
    printf("%s \n",buf);
    return 0;
}