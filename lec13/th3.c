#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int bbb = 0;

void fn_s()
{
	char bufff[10];
	int a = 0; 
	setvbuf(stdout, bufff, _IOFBF, 10);
    	printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int) (0) );
    for (int i = 0; i < 100; i++)
	{
		sleep(1); 
		fn_s(); 
	}
    return 0;

}

int main()
{
//	pthread_t thread2;
//	pthread_t thread3;
	int result1;
//	int result2;
	run((void *)0);
//	pthread_create(&thread2, NULL, run, NULL );
//	pthread_create(&thread3, NULL, run, NULL );
//	pthread_join(thread2, &result2);
	printf("Thread return %d at the end\n", result1);
//	printf("Thread return %d at the end\n", result2);
}

