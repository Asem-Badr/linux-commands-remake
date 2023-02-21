#include "util.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int test_fill_1();
int test_fill_2();

int main(int argc, char **argv)
{
  if (test_fill_1() == 0)
    printf("Test(fill) 1: passed\n");
  else
    printf("Test(fill) 1: failed\n");

  if (test_fill_2() == 0)
    printf("Test(fill) 2: passed\n");
  else
    printf("Test(fill) 2: failed\n");

  return 0;
}

int test_fill_1()
{
  char *str = (char *)malloc(5);
  char *exp = (char *)malloc(5);

  fill(str, 5, 'a');
  fill(exp, 5, 'a');

  if (strcmp(str, exp) == 0)
    return 0;
  else
    return -1;
}

int test_fill_2()
{
  char *str = (char *)malloc(5);
  char *exp = (char *)malloc(5);

  fill(str, 5, 'a');
  fill(exp, 5, 'r');

  if (strcmp(str, exp) == 0)
    return -1;
  else
    return 0;
}