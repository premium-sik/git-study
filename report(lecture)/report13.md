## lec13
* Context Switching
    * 현재 진행하고 있는 Task(Process, Thread)의 상태를 저장하고 다음 진행할 Task의 상태 값을 읽어 적용하는 과정을 말합니다.
    * 진행과정
        1. Task의 대부분 정보는 Register에 저장되고 PCB(Process Control Block)에서 관리.
        1. 현재 실행하고 있는 Task의 PCB 정보를 저장.
        1. 다음 실행할 Task의 PCB 정보를 저장하게 됨.

### Linux Command
* ps
    * 현재 실행중인 프로세스(job) 목록과 상태를 보여준다.
* ps -l
    * 긴 포맷으로 보여준다.

### vi command
* :r (파일명)
    *  파일을 읽는다.
* :!(명령어)
    * 명령어를 실행한다. 그 후에 enter를 누르면 다시 vi editor로 돌아온다.
### fork function
* fork()는 현재 실행되는 프로세스에 대해 복사본 프로세스를 생성하는 함수이다.
* 헤더는 unistd.h이며 함수는 성공시 부모 프로세스는 자식 포르세스의 프로세스 ID를 리턴한다.
* 우선 프로세스는 하나 당 하나씩 유일한 번호가 배정되는데 이때의 번호를 프로세스 ID라고 한다.
* 그리고 자식 프로세스를 만들어준 프로세스를 부모 프로세스라고 하고 fork 함수를 통해 만들어지는 프로세스를 자식 프로세스라고 한다.
* 이 둘은 함수의 리턴값을 통해 확인할 수 있다.

### Thread
* 스레드(thread)란 프로세스(process) 내에서 실제로 작업을 수행하는 주체를 의미합니다.
* 모든 프로세스에는 한 개 이상의 스레드가 존재하여 작업을 수행합니다. 또한, 두 개 이상의 스레드를 가지는 프로세스를 멀티스레드 프로세스(multi-threaded process)라고 합니다.
* 자바에서 스레드를 생성하는 방법에는 다음과 같이 두 가지 방법이 있습니다.
1. Runnable 인터페이스를 구현하는 방법
2. Thread 클래스를 상속받는 방법
두 방법 모두 스레드를 통해 작업하고 싶은 내용을 run() 메소드에 작성하면 됩니다.

### Thread Core 차이
* 우선 CPU의 Core 즉 CPU의 핵심적인 역할을 수행해내는 중심부 역할을 말하며 이 코어에서 시스템의 모든 연산을 처리한다고 보면 되겠다, 즉 CPU에서의 코어가 많은 경우 컴퓨터의 성능을 가장 좌우한다고 볼수도 있다.
* 쓰레드, 멀티쓰레드라고도 표현하며 이 CPU에서의 논리연산을 실제 코어에서 처리한다고 하면 이 코어는 하드웨어 관점에서 바라 봤을때 이고, 멀티쓰레드 또는 멀티쓰레딩 은 소프트웨어 관점에서 논리적인 작업 처리 단위를 나누어 처리한다고 이해하면 된다. 윈도우를 기준으로 현재 구동되고있는 프로세스 들을 체크해보면 코어 단위가 아니라 쓰레드 단위로 취급되고 있어 이를 인텔의 경우 하이퍼쓰레딩이 라는 기술로 코어의 갯수를 논리적으로 반으로 쪼개 작업처리량을 더 늘렸다.
    * 하이퍼쓰레딩 이란
하나의 코어에 쓰레드를 두개로 분리한다, 분리된 논리 코어는 단일 쓰레드 코어보다 더 효율적으로 작업을 처리해낸다, 이전의 다른 작업이 완료되기를 기다리는 유휴 시간을 갖지 않고 CPU가 다음 처리할 내용을 기다리지않고 더 빠른 멀티작업이 가능해진다.
![lec12-2](../Image/lec12-2.jpeg)

### pthread.h
* pthread란 POSIX Thread의 약자로 유닉스계열 POSIX시스템에서 병렬적으로 작동하는 소프트웨어를 작성하기 위하여 제공하는 API입니다. 즉 스레드를 편하게 만들수 있게 도와주는 API이다.
    * API
        * API(Application Programming Interface, 응용 프로그램 프로그래밍 인터페이스)는 응용 프로그램에서 사용할 수 있도록, 운영 체제나 프로그래밍 언어가 제공하는 기능을 제어할 수 있게 만든 인터페이스를 뜻한다. 주로 파일 제어, 창 제어, 화상 처리, 문자 제어 등을 위한 인터페이스를 제공한다.
        * 흔히 API를 레스토랑에 빗대어 표현하기도 한다. 손님(내가 만드는 프로그램)이 자리에 앉아 웨이터(API)에게 주문을 한다. 그럼 웨이터는 내 주문 내역을 주방(API 제공자. 기상청, 공공포탈 등)에 갖다준다. 주방에서 요리를 해 웨이터에게 주면 웨이터가 다시 나에게 음식을 가져다준다. 웨이터가 손님의 주문을 주방으로 전달하는 매개체 역할을 하는 것이다. 여기서 손님은 주방에서 무슨 일이 일어나는지 잘 모른다. 대개는 관심도 없으며 관심을 가질 필요도 딱히 없다. 이것이 API의 장점이다. 내가 가져다쓰려는 API의 기능을 어떻게 구현하는지 몰라도 되고 난 그저 API가 갖다주는 걸 사용만 하면 된다(식사한다)는 것이다. 시간과 노력을 동시에 아낄 수 있다. 이처럼 API는 처음부터 개발하거나 유지 보수할 필요가 없는 외부 데이터와 기능에 접속할 수 있게 해준다.
```
#include <pthread.h>
#include <stdio.h>

void *run (void *arg)
{
    printf("Hello world of POSXI threads.");
    return 0;

}

int main()
{
	pthread_t thread;
	int result; 
	pthread_create(&thread, NULL, run, NULL );
	pthread_join(thread, &result);
	printf("Thread return %d at the end\n", result);
```
### thread.h
```
#include <threads.h>
#include <stdio.h>

int run(void *arg)
{
    printf("Hello world of C11 threads.");
    return 0;
}

int main(int argc, const char *argv[])
{
    thrd_t thread;
    int result;
    thrd_create(&thread, run, NULL);
    thrd_join(&thread, &result);
    printf("Thread return %d at the end\n", result);
}
```
### pthread.h API
```
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
// 생성 함수 start_routine을 실행.
```
```
void pthread_exit(void *retval);
// retval must not in stack
// main thread exit with this, other threads are stilling running.
```
```
int pthread_join(pthread_t thread, void **retval);
```
### pthread.h API
```
void pthread_cancel(pthread_t thread);
// Send cancellation request to thread
```
```
pthread_t pthread_self(void);
//return ID of the calling thread
```
```
int pthread_equal(pthread_t t1, pthread_t t2);
//compare thread IDs
```
