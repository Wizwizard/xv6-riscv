#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("callcount: %d\n", callcount());
  printf("callcount: %d\n", callcount());
  printf("callcount: %d\n", callcount());

  exit(0);
}
