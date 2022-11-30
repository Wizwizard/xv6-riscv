#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char str[100];
  printf("Input the Virtural address in Hex:");
  gets(str,100);
  uint64 va = 0;
  int i = (int)strlen(str) - 2;
  int hexi = i;
  while (1)
  {
    if(i < 0 )
    {
      break;
    }
    long r = hexi-i;
    long result = 1;
     while (r != 0)
    {
        result *= 16;
        --r;
    }
    if((long)str[i]>70)
    {
      va += ((long)str[i]-87)*result;
    }else{
      va += ((long)str[i]-48)*result;
    }
    i--;
  }

  printf("virtual address: %p\n", va );
  myv2p(va);
  exit(0);
}
