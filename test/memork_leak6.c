#include<stdlib.h>

void f()
{
	static char *s;
	char *p;
	p = (char*)malloc(100);
	s = p+1;
}


int main()
{
	f();
}
