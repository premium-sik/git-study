#ifndef __FUNC_

#if FUNCTION_NEGATIVE == 1
#define DF(a) (-(a)*(a))
#else
#define DF(a) ((a)*(a))
#endif 

extern int func1(int x);
extern int func2(int x);
extern int func3(int x);

#endif 
