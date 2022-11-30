# 실전코딩 2 실습

### sshid : pcc020
### name : 윤현식
### id : 202126846

## lec08
### Special Macro and Directives
* ```__FILE__```
    * 파일 이름을 나타낸다.
    * %s
* ```__LINE__```
    * 줄 번호를 나타낸다.
    * %d

### Token stringification
```
#define str(s) #s
str(p = "foo\n";) // outputs "p = \"foo\n\";"
str(\n) // outputs "\n"

#define xstr(s) str(s)
#define str(s) #s
#define foo 4
str (foo) // outputs "foo"
xstr (foo) // outputs "4" 
```
### Token Concatenation
```
#define DELARE_STRUCT_TYPE(name) typedef struct name##_s name##_t

DECLARE_STRUCT_TYPE(g_object);
// Outputs: typedef struct 
g_object_s g_object_t;

#define CAT(a,b) a##b
#define sq(a) a##a##a
sq(C) // Outputs: CCC

// 다른 예제
#define COMMAND(name) {#name, name ## _command}
COMMAND(quit) // -> {"quit", quit_command}
```

### GCC Optimization
* -O0(기본값)
    * 최적화를 수행하지 않는다.
* -O, -O1
    * 코드 크기와 실행 시간을 줄이는 것을 제외한 최적화는 실행하지 않는다.
* -O2
    * 메모리 공간과 속도를 희생하지 않는 범위내의 모든 최적화를 수행한다. (loop unrolling과 function inlining에 대한 최적화를 수행하지 않는다.)
* -O3
    * -O2 최적화에 인라인 함수와 레지스터에 대한 최적화를 추가로 수행한다.
        * 인라인 함수: 실행을 해보면 일반 함수와 다르지 않지만 다음과 같이 인라인 함수는 호출을 하지 않고 함수의 코드를 그 자리에서 그대로 실행합니다. 즉, 컴파일러는 함수를 사용하는 부분에 함수의 코드를 복제해서 넣어줍니다. 즉, 함수 호출 과정이 없으므로 속도가 좀 더 빠릅니다.
        ```
        #include <stdio.h>
        inline int add(int a, int b)
        {
            return a+b;
        }
        int main()
        {
            int num1;
           /*
            num1 = inline int add(10, 20)
            {
                return 10 + 20;
            }
            */
            // 주석 부분을 컴파일러가 함수를 복제해서 넣어줌!
            printf("%d", num1);
        }

* -Os
    * -O2 최적화 기능을 사용하지만, 코드 크기를 증가시키는 최적화는 생략한다.

### .o .s file
![file](../Image/file.jpeg)

### gcc option
* gcc -o (실행파일명) (파일명)
    * 실행파일명으로 실행파일을 만든다.
* gcc -E
    * 전처리 과정의 결과를 화면에 보이는 옵션 (전처리과정 중 발생한 오류를 검증)
* gcc -S
    * cc1으로 전처리된 파일을 어셈블리 파일로 컴파일까지만 수행하고 멈춘다. (*.s)

* gcc -c
    * as에 의한 어셈블까지만 수행하고 링크는 수행하지 않는다. 오브젝트 파일 생성 (*.o)

### Macro Definition (2)
* Multiple lines
    * ```
        #define NUMBERS 1, \
                        2, \ 
                        3
        ```
    * ```
        int x[] = { NUMBERS }; 
        //int x[] = {1,2,3};
      ```
* Define Where?
    * ```
        foo = X;
        #define X 4
        bar = X; // foo = X and bar = 4
      ```
    * ```
        #define TABLESIZE BUFSIZE
        #define BUFSIZE 1024
        // TABLESIZE == BUFSIZE ==1024
      ```
    * ```
        #define BUFSIZE 1020
        #define TABLESIZE BUFSIZE
        #undef BUFSIZE
        #define BUFSIZE 37 // TABLESIZE = 37
      ```
### Macro Definition (3) - Function like Macro
* ```
    #define min (X, Y) ((X) < (Y) ? (X) : (Y))
    x = min(a,b); -> ((a) < (b) ? (a) : (b));
    y = min(1,2); -> ((1) < (2) ? (1) : (2));
    z = min(a + 28, *p) -> z = ((a+28) < (*p) ? (a+28) : (*p));
    // if문 보다 성능이 좋음.
  ```
### 실습 1
```
#include <stdio.h>

void add( int *a, int *b, int *c)
{
        *c = *a + *b;


int main()
}
        int a=100;
        int b = 200;
        int c = 999;
        // int * == long long
        fprintf(stdout, "%d : %lld %llx\n", a, (long long) &a, (long long) &a);
{
        fprintf(stdout, "%d : %lld %llx\n", b, (long long) &b, (long long) &b);
        add(&a, &b, &c);
        fprintf(stdout,"%s %d : %d :\n ", __FILE__, __LINE__, c);
        fprintf(stdout,"%s %d : %d : \n ", __FILE__, __LINE__, c);
        fprintf(stdout,"%s %d : %d : \n ", __FILE__, __LINE__, c);
#define ERR_DATA 1000
#if ERR_DATA > 1000
#error 1024
#else
#warning ERR_DATA
#endif
        fprintf(stdout,"%s %d : %d :\n ", __FILE__, __LINE__, c);


}
```

![lec08-1](../Image/lec08-1.jpeg)

* ```__LINE__```은 몇 번째 라인인지 알려주며, 재정의 할 경우 그 밑줄부터 다시 카운트한다.
* ```__FILE__```은 파일명을 출력한다. 해당 파일의 경우 이름이 hello.c이기 때문에 hello.c를 출력한다.
* &a와 &b가 longlong으로 정의되면 %lld로 출력될 때 warning이 발생하지 않는다.
* ERR_DATA를 1000이라고 했기 때문에 if 문에 걸리지 않고 else로 넘어가 waring문을 띄어준다.

##### 2시 1분 ~ 프젝 설명
* 아주대학교의 임베디드 시스템을 위한 고정소수점 수학 라이브러리 개발.
    * 임베디드 시스템: 특정한 목적을 가지고 만들어진 프로그래밍 가능한 모든 컴퓨터를 의미한다. 더 큰 시스템 내에서 특정 기능을 위해 설계된 기능으로 고정되거나 프로그래밍 가능한 컴퓨터 하드웨어와 소프트웨어의 조합이라 할 수 있다.
    * 고정소수점 표현 방식: 10진수를 2진수로 바꿨으면, 그걸 그대로 박아넣는 방식.
    * 부동소수점 표현 방식: 2진수로 변환한 결과를 그대로 박아넣지 않고 몇 가지 과정을 추가로 거친다.
        * 정규화(Normalization):  정수부에 1만 남을 때까지 소수점을 왼쪽 (*정수부가 0일 경우엔 오른쪽. 아래에서 다시 설명) 으로 이동시키고 이동한 칸 수만큼 n 자리에 집어넣으면 된다. 예를 들어서 111.101을 정규화하면 1.11101 * 2^2가 된다.
        * IEEE 754: IEEE 754의 부동소수점 표현은 크게 세 부분으로 구성되는데, 최상위 비트는 부호를 표시하는 데 사용되며, 지수 부분(exponent)과 가수 부분(fraction/mantissa)이 있다.
            * −118.625(십진법)를 IEEE 754(32비트 단정밀도)로 표현해 보자.
            * 음수이므로, 부호부는 1이 된다.
            * 그 다음, 절댓값을 이진법으로 나타내면 1110110.101(2)이 된다. 소수점을 왼쪽으로 이동시켜, 왼쪽에는 1만 남게 만든다. 예를 들면 1110110.101(2)=1.110110101(2)×2⁶ 과 같다. 이것을 정규화된 부동소수점 수라고 한다.
            * 가수부는 소수점의 오른쪽 부분으로, 부족한 비트 수 부분만큼 0으로 채워 23비트로 만든다. 결과는 11011010100000000000000 이 된다.
            * 지수는 6이므로, Bias를 더해야 한다. 32비트 IEEE 754 형식에서는 Bias는 127이므로 6+127 = 133이 된다. 이진법으로 변환하면 10000101(2)이 된다.
            * ![IEEE](../Image/IEEE.jpeg)
