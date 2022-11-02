#include<stdlib.h>

char *f()
{
	return (char *)malloc(100);
}

int main()
{
	f();
}
