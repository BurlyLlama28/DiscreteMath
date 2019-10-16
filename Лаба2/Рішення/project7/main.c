#include <stdio.h>
#include <stdlib.h>

int main()
{
  int b=0;
  for(int n=1;n<1000;n++)
  {
      if (n%11==0||n%17==0)
      {
        b++;
      }
  }
  printf("We have %d numbers\n",1000-b);
    return 0;
}
