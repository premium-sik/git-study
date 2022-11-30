#include <stdio.h>

int main()
{
	char a;
	short b;
	int c;
	long long d;
		
	scanf("%hhd %hd %d %lld\n", &a, &b, &c, &d);
	printf("%hhd %d %d %lld\n", a, b, c, d);
}
