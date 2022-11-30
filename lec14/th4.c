#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


int bbb = 0; 

void fn_s()
{
    	static int a = 0; 
    	printf("<= %d %d =>",a++, bbb++);
	fflush(stdout);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int) pthread_self() );
    for (int i = 0; i < 1000; i++)
	{
//		usleep(1000000); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	int result1, result2, result3;
//    	char bufff[10]; 
//    	setvbuf(stdout,bufff,  _IONBF, 10); 
	pthread_create(&thread1,NULL, run, NULL);
	pthread_create(&thread2,NULL, run, NULL);
	pthread_create(&thread3,NULL, run, NULL);
	printf("JUST AFTER THR Create\n", result1);
	run((void *) 0); 
	pthread_join(thread1, (void **) &result1);
	pthread_join(thread2, (void **) &result2);
	pthread_join(thread3, (void **) &result3);
	printf("\nThread return %d at the end\n", result1);
	printf("\nThread return %d at the end\n", result2);
	printf("\nThread return %d at the end\n", result3);
}

