#include <stdio.h>
#include "helper.h"

int main(int argc, char **argv)
{
    FILE * file ;
    int line_count =10 ,char_count =0; //will be flexible soon
    char buffer[buffer_size];
    file = fopen(one_arg(argc,argv),"r");
    int beginning = ftell(file);
    fseek(file,0,SEEK_END);
    char ch ;
    //the second part of the condition handles the case of 
    //the file being shorter than 10 lines
    while (line_count &&ftell(file)!=beginning)
    {
        ch =getc(file);
        if(ch =='\n')
        {
            line_count --;
        }
        char_count --;
        fseek(file,char_count,SEEK_END);
    }
    fseek(file,char_count+2,SEEK_END);
    while(fgets(buffer,buffer_size,file)!=NULL)
    {
        printf("%s",buffer);
    }
    fclose(file);

    return 0;
}