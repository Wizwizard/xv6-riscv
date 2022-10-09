#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int fd = 10;

  close(fd);
  callcount();
  callcount();
  callcount();
 // printf("callcount:%d\n", callcount());

  exit(0);
}
