#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    fprintf(2, "Usage: mksmfdir files...\n");
    exit(1);
  }

  for(i = 1; i < argc; i++){
    if(mksmfdir(argv[i]) < 0){
      fprintf(2, "mksmfdir: %s failed to create\n", argv[i]);
      break;
    }
  }

  exit(0);
}