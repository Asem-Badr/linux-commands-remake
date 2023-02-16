#ifndef LS_H
#define LS_H

#define TRUE 1
#define FALSE 0
#define OPTIONS_LENGTH 2

void check_options(int *a, int *f, int *l, int *lh, int argc, char **argv,char**buffer);
int compareTwoString(char *a, char *b);
void print_results(char*file_name,struct stat fileStat ,int a, int f, int l, int lh);
void print_file_name(char *file_name);
void print_permissions(char *file_name , struct stat fileStat);
int check_if_hidden(char *file_name);

#endif