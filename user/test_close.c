#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  // init a fd with 10
  // however the fd it not a acutal open file fd
  int fd = 10;
  close(fd);

  exit(0);
}
