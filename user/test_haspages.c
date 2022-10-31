#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  uint32 p_id = 1;
  has_pages(p_id);
  exit(0);
}
