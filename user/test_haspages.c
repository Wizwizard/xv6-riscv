#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  uint32 p_id = getpid();
  haspages(p_id);

//   // malloc 4096
//   char * str;
//   str = (char *) malloc (4096);

//   haspages(p_id);
//   // malloc another 4096
//   char * str2;
//   str2 = (char*) malloc (4096);

//   haspages(p_id);

//   // free first
//   free(str);
//   haspages(p_id);

//   // free next
//   free(str2);
//   haspages(p_id);


  if((p_id=fork()) == 0) {
    char *str;
    str = (char*)malloc(4096);
    p_id = getpid();
    haspages(p_id);
    free(str);
    haspages(p_id);
  } else{
    haspages(p_id);
  }

  exit(0);
}
