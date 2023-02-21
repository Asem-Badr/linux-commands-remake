#include "util.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  char *str = (char *)malloc(5);
  char *exp = (char *)malloc(5);

  fill(str, 5, 'a');
  fill(exp, 5, 'r');

  if (strcmp(str, exp) == 0)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}