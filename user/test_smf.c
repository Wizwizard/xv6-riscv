#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int
main(int argc, char *argv[])
{
    int fd = open("smfdir/sfile1", O_CREATE|O_WRONLY);
    if(fd < 0){
      printf("open(smfdir/sfile1) failed\n");
      exit(1);
    }

    char * sin = "123";

    int n = write(fd, (void*)sin, strlen(sin));
    if(n >= 0){
      printf("write(fd, %s, %d) returned %d, not -1\n", sin, strlen(sin), n);
      exit(1);
    }

    close(fd);

    int fd = open("smfdir/sfile1", O_RDONLY);
    if(fd < 0){
      printf("open(smfdir/sfile1) failed\n");
      exit(1);
    }

    char * sout = (char *)malloc(10*sizeof(char));

    int n = read(fd, (void*)sout, strlen(sin));
    if(n > 0){
      printf("read(fd, %s, %d) returned %d, not -1 or 0\n", sout, strlen(sin), n);
      exit(1);
    }
    close(fd);
}
