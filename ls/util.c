#include "util.h"
#include "ls.h"
#include <stdio.h>
#include <string.h>

int fill(char *str, int len, char c)
{
  for (int i = 0; i < len - 1; i++)
  {
    str[i] = c;
  }
  str[len] = '\0';
  return 0;
}

// int is_exists(char c, char *str)
// {
//   for (int i = 0; i < strlen(str); i++)
//   {
//     if (c == *(str + i))
//     {
//       return 1;
//     }
//   }
//   return 0;
// }

// int get_options(char *opt, int argc, char **argv)
// {
//   int cnt = 0;
//   for (int i = 1; i < argc; i++)
//   {
//     char *arg = *(argv + i);

//     if (arg[0] != '-')
//       continue;

//     for (int j = 1; j < strlen(arg); j++)
//     {
//       if (!(is_exists(arg[j], OPTIONS)))
//       {
//         return -1;
//       }

//       if (!(is_exists(arg[j], opt)))
//       {
//         opt[cnt] = arg[j];
//         cnt++;
//       }
//     }
//   }
//   return 0;
// }