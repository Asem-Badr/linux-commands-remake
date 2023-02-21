#include "util.h"
#include <stdio.h>

int fill(char *str, int len, char c)
{
  for (int i = 0; i < len; i++)
  {
    str[i] = c;
  }
  return 0;
}