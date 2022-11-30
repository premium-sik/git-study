### int const * 와 int * const의 차이
 ```
 #include <stdio.h>
 void add(int *a, int *b, int *c)
 {
     *c = *a + *b;
 }
 int main()
 {
     int const a = 100;
     int b = 200;
     int c = 9999;
     int const * p = &a;
     fprintf(stdout, "a, b ,c : %d %d %d\n", p, b, c);
     p = &b;
     fprintf(stdout, "a, b ,c : %d %d %d\n", p, b, c);
 }
```
* int const * 는 const int형을 가리키는 포인터로 포인터 값은 변경이 가능하므로 다른 것을 가리킬 수 있으나 내부의 int 값은 const로 선언되어 변경이 불가능합니다.
* int* const 는 const 포인터가 int형을 가리키고 있으므로 포인터의 값은 변경이 불가능하고 내부의 int형으로 표현된 값은 변경이 가능합니다. 
