#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("System call: %d\n", system("ls-li test.c zzz"));
	return 100;
}

