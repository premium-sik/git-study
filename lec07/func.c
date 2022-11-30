#include "func.h"
#define __FUNC_ 0

#if __FUNC_ == 0 
int func1(int a)
	
{
	return(a*10);
}

int func2(int a)
{
	return DF(a+1)*20;
}
#else

int func3(int a)
{
	return DF(a+2)*20;
}
#endif
