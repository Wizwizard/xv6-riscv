#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  uint32 p_id = 1;
  haspages(p_id);
  exit(0);
}
