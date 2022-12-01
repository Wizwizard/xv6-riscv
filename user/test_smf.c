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

    // rmv test_dir if exist
    char * test_dir = "smfdir1";
    unlink(test_dir);

    // create test_dir
    mksmfdir(test_dir);

    char * sout = (char *)malloc(100);


    // test basic small file read & write
    printf("\ntest basic small file read & write\n");

    char * test_file1 = "smfdir1/sfile1";
    char * sin = "basic test;";

    int fd, n;
    fd = open(test_file1, O_CREATE|O_WRONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }


    n = write(fd, (void*)sin, strlen(sin));
    if(n >= 0){
      printf("write(fd, %s, %d) returned %d, not -1\n", sin, strlen(sin), n);
    }

    close(fd);

    fd = open(test_file1, O_RDONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }


    n = read(fd, (void*)sout, strlen(sin));
    if(n > 0){
      printf("read(fd, %s, %d) returned %d, not -1 or 0\n", sout, strlen(sin), n);
    } 
    close(fd);

    // test append data into the small file and read

    printf("\ntest append data into the small file and read\n");

    char * sin2 = "append test;";


    fd = open(test_file1, O_WRONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }


    n = write(fd, (void*)sin2, strlen(sin2));
    if(n >= 0){
      printf("write(fd, %s, %d) returned %d, not -1\n", sin2, strlen(sin2), n);
    }

    close(fd);

    fd = open(test_file1, O_RDONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }

    n = read(fd, (void*)sout, strlen(sin) + strlen(sin2));
    if(n > 0){
      printf("read(fd, %s, %d) returned %d, not -1 or 0\n", sout, strlen(sin) + strlen(sin2), n);
    } 
    close(fd);

    // test overflow 
    printf("\ntest overflow\n");

    char * sin3 = "overflow!overflow!overflow!overflow!overflow!overflow!overflow!overflow!overflow!";

    fd = open(test_file1, O_WRONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }

    n = write(fd, (void*)sin, strlen(sin3));
    if(n >= 0){
      printf("write(fd, %s, %d) returned %d, not -1\n", sin3, strlen(sin3), n);
    } else {
        printf("write(fd, %s, %d) returned %d \n", sin3, strlen(sin3), n);
    }

    close(fd);

    // read exceed size

    printf("\ntest read exceed size\n");


    fd = open(test_file1, O_RDONLY);
    if(fd < 0){
      printf("open(%s) failed\n", test_file1);
      exit(1);
    }

    n = read(fd, (void*)sout, 100);
    if(n > 0){
      printf("read(fd, %s, %d) returned %d, not -1 or 0\n", sout, 100, n);
    } 
    close(fd);

    return 0;
}