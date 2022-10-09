#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int cpid = 0;
    for(int i = 0; i < 5; i ++) {
        if ((cpid=fork()) > 0) {
            printf("child process%d start! \n", cpid);
        } else {
            for (int j = 0; j < 2000; j ++) {
                if (j % 100 == 0) {
                    printf("child process%d running %d\n", getpid(), j);
                }
            }
	    break;
        }
    }
    exit(0);
}
