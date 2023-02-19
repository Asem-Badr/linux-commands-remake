#ifndef LS_H
#define LS_H

#define TRUE 1
#define FALSE 0
#define BOOL int
#define OPTIONS_LENGTH 5
void check_options(int argc, char**argv);
int compareTwoString(char *a, char *b);
void print_results(char*file_name,struct stat fileStat);
void print_file_name(char *file_name);
void print_permissions(char *file_name , struct stat fileStat);
int check_if_hidden(char *file_name);
BOOL contains_char(char*str , char target);

#endif