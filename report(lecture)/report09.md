## lec09
### C언어 구조체(구조체 포인터 / typedef)
```
/// 구조체 정의
#include <stdio.h>

//구조체 정의
struct Student
{
  int id;
  int age;
  char * name;
};  // 세미콜론 확인

int main()
{                      //구조체 변수 선언
  struct Student stu;  //자료형 Student 의 변수 stu 선언 
                       
  stu.id = 1001;   //구조체 안 멤버에 접근하려면 . 연산자(직접접근)
  stu.age = 20;
  stu.name = "nano";

  printf("id : %d\n", stu.id);
  printf("age : %d\n", stu.age);
  printf("name : %s\n", stu.name);
  
  return 0;
}
```
```
// typedef는 기존의 존재하는 자료형에(구조체) 새 이름을 부여하는 것입니다.

typedef int InT; 
InT num=10;

int num=20; //기존 자료형도 물론 사용가능
```

### 프로젝트 관련 코드
```
#include <stdio.h>
// #### #### #### #### .  #### #### #### ####
// S 15 . 16
#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05F
#define FX_2_PLUS_16 (1<<16)
#define FX_S_15_15 11516
#define FX_SYSTEM FX_S_15_16

typedef int fixed32;

fixed32 fromFloat(float fa)
{
        return (fixed32)(fa * FX_2_PLUS_16);

}


float toFloat(fixed32 xa)
{
        return ((float) (xa)) * FX_2_MINUS_16;
}

fixed32 fxAdd(fixed32 a, fixed32 b)
{
        return fromFloat((toFloat(a) + toFloat(b)));
}
fixed32 fxAdd2(fixed32 a, fixed32 b)
{
        return a+b;
}
int main()
{
        long long i=0;
        int ia, ib, ic, ic2;
        float fa;
        fscanf(stdin,"%d %d", &ia, &ib);
        for(i=0; i<  64*256*256*256; i+=(256*256))
        {
                ic = fxAdd(i, i);
                ic2 = fxAdd2(i, i);
                //fprintf(stdout, "%d + %d : %d\n", ia, ib, ic);
                fprintf(stdout, "%f + %f :  %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2), ic-ic2);
                fprintf(stdout, "%d + %d :  %d\n",ia, ib, ic);
        }
}
```
* typedef int fixed32; 를 통해 fixed32는 int와 같은 효과를 지니게 된다.
* 변수 i를 long long 자료형으로 선언하여 오버플로우가 일어나지 않도록 한다.
* 그리고 fxAdd 함수에서는 a, b를 fixed32(int)로 받아 fromFloat 함수로 보내고 이 함수에서 보낸 변수를 tofloat에서 fixed32 형태로 받아드리고 2^-16을 곱한 값을 반환한다. 그리고 다시 fromFloat에서 2^16이 일어나고 최종적으로 덧셈 연산 후 fixed32(int)형으로 반환한다.
* fxAdd2 함수에서는 a, b를 fixed32(int)로 받아 덧셈 연산을 수행하고 반환한다.

### cc 옵션
* cc -g
    * gdb에게 제공하는 정보를 바이너리에 삽입한다.
    * -g 옵션을 사용하지 않고 gdb로 디버깅하면, 역어셈 → 어셈블리 코드로만 디버깅 가능하다.

* cc -pg
    * 프로파일을 위한 코드를 삽입한다. 
    * -pg 옵션으로 컴파일 → gmon.out(프로파일 정보) → gprof로 gmon.out 파일 분석


### gdb 디버거 명령어
* 실행파일과 소스파일이 같은 디렉토리에 있어야 제대로 동작한다.
* gdb (실행파일)
    * 시작
* run
    * 프로그램 실행
* break (line or *address)
    * 정지점
    * break 34: 34번째 line에 정지점 생성
    * break fxAdd: fxAdd가 들어있는 line에 정지점 생성.
* delete breakpoints
    * 정지점 모두 지우기
* clear 
    * 정지점 삭제
    * clear 4: 4번째 정지점 삭제.
* step
    * 현재 행 수행 후 정지, 함수 호출시 함수 안으로 들어감
    * step 5: step 명령어 5번 수행
* next
    * 현재 행 수행 후 정지, 함수 호출시 함수 수행 다음 행으로 넘어감
    * next 5: next 명령어를 5번 수행.
* list
    * 소스 파일의 내용을 출력
    * list 4,7: 4번째~7번째 라인의 소스만 출력.
* continue
    * 다음 브레이크 포인트까지 코드를 실행한다.
* watch (변수명)
    * 해당 변수에 watchpoint를 설정하고 해당 변수가 바뀔 때마다 현재값을 출력한다.
* print
    * 변수/주소 등을 출력한다.
* Quit (or q)
    * 종료
