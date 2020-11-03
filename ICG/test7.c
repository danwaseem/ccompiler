// passing wrong parameters to a function

#include <stdio.h>

int hello(int A)
{
  A=A+5;
  return A;
}

void main()
{
    int q = 5, j = 10;

    hello(q, j);
}
