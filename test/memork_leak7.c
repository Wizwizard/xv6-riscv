#include<stdlib.h>

void f()
{
	static char *s;
	if(s==NULL) s=(char*)malloc(100);
}


int main()
{
	f();
}
