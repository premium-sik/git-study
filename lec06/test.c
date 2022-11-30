#include <stdio.h>

void add(int *a, int *b, int *c)
{
	*c = *a + *b;
}

int main()
{
	const int a = 100;
	int b = 200;
	const int c = 999;

	fprintf(stdout, "%d : %lld\n", a, &a);
	fprintf(stdout, "%d : %lld\n", b, &b);
	add(&a,&b,&c); //2
//	c = a+b; //1
	fprintf(stdout, "%d : %lld\n", c, &c);
	int d=999; 
	fprintf(stdout, "%d :%lld  %lld\n", d, ((void *)(&d))+1, &d+1);
		}
