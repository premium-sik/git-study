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
     fprintf(stdout, "a, b ,c : %d %d %d\n", a, b, c);
     *p = 200;
     fprintf(stdout, "a, b ,c : %d %d %d\n", a, b, c);
 }
