# 실전코딩 2 실습

### sshid : pcc020
### name : 윤현식
### id : 202126846
## lec04

### understanding redirection 
* < = 0<, << = 0<<, > = 1>, >> = 1>>, 2> = 2>>
* echo hello > /tmp/out - hello를 tmp/out에 저장. <br>
= echo > /tmp/out hello <br>
* echo hell0 >&2 - stdout, stderr 둘다 내보낸다. <br>
= echo >&2 hello
* read -r line < file - file의 한 줄을 읽는다. <br>
= < file read -r line
* 단축코드
    * mycomn > outfile 2>&1 을 줄여서 mycomn &> outfile
    * mycomn >> outfile 2>&1 을 줄여서 mycomn &>> outfile
    * mycomn1 2>&1 | mycomm2 을 줄여서 mycomm1 |& mycomm2
    * https://mug896.github.io/bash-shell/redirections.html
### Here document, Here String
* 0<<, <<
    *  임시 파일을 만들어 stdin으로 연결. <br>
    ```
    $cat << EOF
    > "200"
    > EOF
    "200"
    ```
* <<< (bash only)
    * string을 stdin 입력으로 연결.
    ```
    $ cat <<< *
    *
    ```
### Pipe Oreder of execution
* 실행의 순서는?
    * $ cmd1 | cmd2
        * cmd1과 cmd2는 동시에 병렬로 실행된다.
        * cmd1이 cmd2보다 빠르면 파이프에 write은 블록되고 더이상 진행되지 않는다.
        * cmd2가 cmd1 보다 빠르면 파이프로부터의 read는 블록된다.
        * cmd1이 먼저 종료하면 파이프는 close 되고 cmd2는 End-Of-File 로 인식해 종료한다.
        * cmd2가 먼저 종료하면 파이프는 close 되고 cmd1은 다음번 write에 SIGPIPE 신호를 받게되고 종료된다.
### Named pipe
* pipe는 자동으로 생성/소멸
* Named pipe
    * mkfifo 명령으로 생성 - 파일처럼 생성됨.
    * redirection으로 sending
* 읽는 상대편이 없으면 Block 된다.
* Buffer Control이 필요.

### linux command
* ????*
    * 이름이 4글자 이상인 파일들을 모두 보여주는 명령어.
* echo [abc]*
    * 이름이 a, b, c로 시작하는 파일들을 모두 보여주는 명령어.
* echo [a-q]*
    * 알파벳 사전순으로 a~q까지의 알파벳으로 시작되는 파일을 모두 보여주는 명령어.

### Standard signed integer type
* signed char, short int, int, long int, long long int
* Unsigned
    * Unsigned ...
* floating type
    * flout, double, (long double)
* Definition in standard
    * char - large enough to store any execution character set.
    * floating - The set of values of the type float is a subset of the set of values of the type double; the set of values of the type double is a subset of the set of values of the type long double.
* _complex
* _Bool
    * can store 0, 1

### Negative integer
* 3 Well know methods to represent signed integer
    * the corresponding value with sign bit 0 is negated (sign and magnitude);
    * the sign bit has the value - (2M)(two's complement);
    * the sign bit has the value (2M-1)(one's complement).
* Which method is used in C Language?
    * All three are possible.
    * 근데 대부분은 2's complement를 사용.
    * 2'complement
        * 1의 보수(~)를 구한 후, 가장 낮은 비트에 +1
     
### Unsigned int
* un-sign-ed 라는 것은 결국 "부호가 없다"는 뜻이고, 그래서 항상 플러스 값만 가짐.
* %u를 통해 출력.

### 시프트 연산
* '>>': /2
* '<<': *2

### signed int 와 unsigned int에서 시프트 연산의 차이
```
int in_a, in_b;
fscanf(stdint, "%d", &in_a);
in_b = in_a >> 2;
```
signed int의 경우 a에 음수 값을 넣고 오른쪽으로 두칸 이동할 때 남는 공간에 1이 채워진다. 양수 값일 경우 0이 채워짐.
```
unsigned int in_a, in_b;
fscanf(stdint, "%d", &in_a);
in_b = in_a >> 2;
```
unsigned int의 경우 a에 음수 값을 넣고 오른쪽으로 두칸 이동할 때 남는 공간에 0이 채워짐. 양수 값일 경우 1이 채워짐.

나누기 연산에서도 같은 현상이 일어남.
