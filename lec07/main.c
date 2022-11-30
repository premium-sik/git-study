#include <stdio.h>
#define FUNCTION_NEGATIVE 1
#include "func.h"
#define __FUNC_ 0
int main()
{
	printf("func1 %d %d\n", func1(100), DF(10));// func 110 100

	printf("func2 %d %d\n", func2(100), DF(10));// func 110 100

}
