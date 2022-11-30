# 실전코딩 2 실습

### sshid : pcc020
### name : 윤현식
### id : 202126846

## lec06
###linux command
* alias
    * 자주 사용하는 명령어를 특정 문자로 입력해두고 간편하게 사용하기 위한 것으로 command alias라고 함. <br>
    alias = cc='cc-Wall' 이런식으로 사용 가능.
    * alias -p를 통해 확인 가능.
    * unalias를 통해 해제 할 수 있음. 이때, unalias -a은 모든 alias 설정을 삭제.
    * alias 설정한 것을 사용하고 싶지 않을 때는 \ls 처럼 \를 붙여 사용.
* cc && a.out
    * 컴파일 후 문제가 없을 경우 a.out을 실행하는 명령어.
* cc ; a.out
    * 컴파일 후 a.out을 실행하는 명령어. 이때 컴파일 에러가 발생하면 가장 최근에 컴파일 성공한 a.out의 결과를 출력. 
* cc || echo "Errrr"
    * 컴파일 에러가 날 경우 echo의 결과를 출력해주는 명령어.

### Pointer Basic
* &val - val의 주소.
    * %lld로 받음.
* *ptr - val 주소의 값.
    * *&a는 a가 가리키는 주소의 값.


* increment
    * int *a; // a++ increment by 4
    * long long *b; // b++ increment by 8
    * void *c; // c++ increment by 1

```
#include <stdio.h>

void add(int *a, int *b, int *c)
{
        *c = *a + *b;
}

int main()
{
        const int a = 100;
        int b = 200;
        const int c = 999;

        fprintf(stdout, "%d : %lld\n", a, &a);
        fprintf(stdout, "%d : %lld\n", b, &b);
        add(&a,&b,&c); //2
//      c = a+b; //1
        fprintf(stdout, "%d : %lld\n", c, &c);
        int d=999;
        fprintf(stdout, "%d :%lld  %lld\n", d, ((void *)(&d))+1, &d+1);
                }

```
위 코드의 경우 c를 1번과 같이 구할 경우와 2번으로 구하는 경우가 다르다. add함수로 갈 경우 c의 주소의 값을 수정하는 것이기 때문에 오류가 발생하지 않지만 1처럼 그냥 수정하려고 한다면 const int이기 때문에 오류가 발생한다. 마지막 fprintf 에서 자료형을 int에서 void로 바꾸어주는데 이 때문에 메모리 크기가 4에서 1로 바뀌고 &d+1 은 메모리 주소가 int와 다르게 1만 증가하게 된다.<br>
또한 add 함수에서 *b = *(a+1) 와 같이 나타낼 수 있는 것은 이것들이 메모리 주소 형태로 들어왔기 때문에 가능하다.

### int an_array[ ] vs int *a_pointer 
* int an_anrray[32]; (이건  int로 저장되서 4 byte, an_array 자체는 8byte 공간에 저장.)
    * Program will do;
    * set aside a space on the stack big enough for 32 integers, and
    * declare that an_array is a pointer, and
    * bind that pointer to point to the newly allocated space.
* int *a_pointer;
    * Just pointer;
    * a_pointer = malloc(32*4);

```
#include <stdio.h>

int sumArray3(int a[3], int sum)
{
        sum = *a;
        a++;
        sum += *a;
        a++;
        sum += *a;
        fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
        return a[3];
}

int main()
{
        int a=100;
        int b = 200;
        int c = 999;
        int arr[4] = {100,200,300,400};
        int *parr;
        parr = arr;
        parr++;
        fprintf(stdout, "%d : %lld %lld\n", *parr, parr, arr);
         c = sumArray3(arr, b);
        fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);

        fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
        fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
        fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
        fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
        fprintf(stdout, "%d : %lld %llx\n", arr[4000], &arr[4000], &arr[4000]);

}

```
위 코드를 처럼 arr 배열을 선언하여 출력하면 <br>
![lec06p](../Image/lec06p.jpeg) 
* 위 사진과 같은 결과를 얻을 수 있다. 이 사진이 의미하는 것은 우선 arr가 각각 %d, %lld로 출력될 때 각각의 주소값의 int 값과 본래 값인 140735337148832이 출력된 것을 볼 수 있다. 
* 또한 바로 밑에 arr[2]가 출력된 것을 보면 주소가 8 증가한 것으로 보아 int arr로 선언되었기에 메모리 값이 4씩 증가하는 것이 확인된다. 
* main함수에서 sumArray3 함수로 arr, b를 보내지만 b의 값은 바뀌지 않고 sum이라는 변수가 하나 생기게 된다. b는 Call by value이기 때문에 값이 보존되어 또 다른 sum이라는 변수가 생성되는 것이다. 또한 a의 주소 변경을 통해 값을 바꿀 수 있는 것을 sum += *a; a++;을 통해 알 수 있다. 
* 마지막으로 arr은 const이기 때문에 arr++;처럼 직접 바꾸려고 하면 에러가 발생한다. 그러므로 int *parr과 같이 따로 포인터를 만들어서 해야된다.

### Call by value, Call by reference의 차이
* Call by value(값에 의한 호출)는 인자로 받은 값을 복사하여 처리를 한다. Call by reference(참조에 의한 호출)는 인자로 받은 값의 주소를 참조하여 직접 값에 영향을 준다. 간단히 말해 값을 복사를 하여 처리를 하느냐, 아니면 직접 참조를 하느냐 차이인 것이다.

### Pointer / Address
>* Noun-Adjective Form
    int const A constant integer <br>
    int const * A (variable) pointer to a constant integer <br>
    int * const A constant pointer to a (variable) integer <br>
    int * const * A pointer to a constant pointer to an integer <br>
    int const * * A pointer to a pointer to a constant integer <br>
    int const * const * A pointer to a constant pointer to a constant integer <br>
