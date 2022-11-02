#include<stdlib.h>

struct outer{

int a;
int b;
char* buf;
};

int main()
{
	struct outer *p = (struct outer *) malloc(sizeof(struct outer));
	p->buf = (char *)malloc(sizeof(100));
	//free(p);
}
