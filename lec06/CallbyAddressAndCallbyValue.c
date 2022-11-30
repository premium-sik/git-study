#include <stdio.h>

void addPointer(int *a, int *b, int *c)
{
	*c =  *a + *b;
	fprintf(stdout, "In addPointer A %d : %lld %llx\n", *a, a, a); 
	fprintf(stdout, "In addPointer B %d : %lld %llx\n", *b, b, b); 
	fprintf(stdout, "In addPointer C %d : %lld %llx\n", *c, c, c); 
	*a = -100;
	*b = -200; 
}

int addValue(int c, int b, int a)
{
	c =  a + b;
	fprintf(stdout, "In addValue A %d : %lld %llx\n", a, &a, &a); 
	fprintf(stdout, "In addValue B %d : %lld %llx\n", b, &b, &b); 
	fprintf(stdout, "In addValue C %d : %lld %llx\n", c, &c, &c); 
	a = 999; b=888;
	return c; 
}

int main()
{
	int a = 100, b = 200, c = 999;

	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a); 
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b); 
	addPointer(&a,&b,&c); 
	fprintf(stdout, "%d : %lld %llx\n", c, &c, &c); 
	// a = 200; b = 300; 
	c = addValue(a,b,c); 
	fprintf(stdout, "%d : %lld %llx\n", a, &a, &a); 
	fprintf(stdout, "%d : %lld %llx\n", b, &b, &b); 
	fprintf(stdout, "%d : %lld %llx\n", c, &c, &c); 
}

