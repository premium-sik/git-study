#include <stdio.h>
//hi


void add( int *a, int *b, int *c)
{
	*c = *a + *(a+1);
}
int main()
{
	int a=100;
	int b = 200;
	int c = 999;
	cinst int arr[4] = {100,200,300,400};
	c = sumArray3(arr);
	// int * == long long 
	fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
	fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
	fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
	fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
	fprintf(stdout, "%d : %lld %llx\n", arr[4], &arr[4], &arr[4]);
	

}	
