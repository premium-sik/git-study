#include <stdio.h>
//hi

void add( int *a, int *b, int *c)
{*c = *a + *b;}

void sub(int *a, int *b, int *c)
{*c = *a - *b;}

void div( int *a, int *b, int *c)
{*c = (*a) / (*b);}

void mul( int *a, int *b, int *c)
{*c = (*a) * (*b);}


int main()
{
	int a = 100;
	int b = 200;
	int c = 9999;
	char ch;
	int op = 0;
	
	scanf("%d %c %d", &a, &ch, & b);
	// ch = + add, - sub, * mul, /div
	switch (ch)
	{
		case '+':
			op = 0;
			break;
		case '-':
			op = 1;
			break;
		case '*':
			op = 2;
			break;
		case '/':
			op = 3;
			break;
	}


	void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};
//	int const *p = &a;
//	int * const q = &a;
//	write difference

	if(op == 0)
	{
		fp[0](&a,&b,&c);
		fprintf(stdout, "%d\n", c);
	}

	if(op == 1){
		fp[1](&a,&b,&c);
		fprintf(stdout, "%d\n", c);
	}
	if(op == 2){
		fp[2](&a,&b,&c);
		fprintf(stdout, "%d\n", c);
	}	
	if(op == 3){
		fp[3](&a,&b,&c);
		fprintf(stdout, "%d\n", c);
	}	
	fprintf(stdout, "fp %lld %lld %lld %lld", add, sub, mul, div);
}
