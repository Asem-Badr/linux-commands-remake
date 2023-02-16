#ifndef HELPER_H
#define HELPER_H

#define safeFree(p) saferFree((void**)&(p))
#define buffer_size 1024
char* one_arg(int argc , char **arcv);
char** many_args(int argc ,char **argv);
void saferFree(void **pp);
#endif

