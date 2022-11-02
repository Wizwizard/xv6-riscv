#include<stdlib.h>

int main()
{

	char **ps = (char**)malloc(1*sizeof(char*));
	*ps = (char*)malloc(100);

	free(ps);

	return 0;
}
