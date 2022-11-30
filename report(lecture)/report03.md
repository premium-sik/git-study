# 실전코딩 2 실습

### sshid : pcc020
### name : 윤현식
### id : 202126846

## lec03

### linux command
1. which (찾고자 하는 것)
   * 파일이 어디있는지 알려주는 명령어.
1. grep
   * 입력으로 전달된 파일의 내용에서 특정 문자열을 찾고자할 때 사용하는 명령어.
1. tee
* ![tee](../Image/tee.jpeg)
   *  명령어의 출력 결과를 파일과 화면에 동시에 출력할 수 있도록 해주는 명령어. stdin을 받아서 stdout과 하나 이상의 파일에 그 입력을 출력.

 ```
 cp ~hwan/.profile ~hwan/.bashrc ~hwan/.bash_logout ~
 source .profile
 ```
 교수님 코드를 카피하여 프롬프트가 초록색이 됨. 또한 path에 .이 추가되어 a.out만 입력해도 실행됨.


### md 사용법
* 제목: #
* 제목 2단: ## -> 제목 6단까지 가능. 
* *은 리스트를 만들 때 유용, Tab을 써서 구분
* <b.r> 을 통해 줄 구분. (.제외)
* 1.을 통해 번호를 매길 수 있으며, 1만 써도 자동으로 번호가 카운트. tab을 하면 다른 리스트로 분류되어 숫자가 리카운트.
* 순수하게 1.을 쓰고 싶다면 1과 .사이에 \ 넣으면 됨.
* ** ** 사이에 글자를 넣으면 bold 되고 * * 사이에 넣으면 이태리체가 됨. *** ***은 이태리 bold가 됨.
* 글자 끝에 #을 넣어 줄 구분.

### git command
* git clone https://git.ajou.ac.kr/sw_hyeonsik/pcc020.git
   * 해당 git 사이트에 있는 소스코드를 복제하여 내 컴퓨터에 가져옴.
* git pull
   * 원격 저장소에서 로컬 저장소로 소스를 가져오는 명령어.
* git add
   * 작업 디렉토리(working directory) 상의 변경 내용을 스테이징 영역(staging area)에 추가하기 위해서 사용.<br>다음 변경(commit)을 기록할 때까지 변경분을 모아놓기 위해서 사용.
* git commit -m ""
   * commit은 파일 및 폴더의 추가/변경 사항들에 대해 기록을 하는 것, 작업공간 안에 있는 모든 파일과 파일의 데이터를 사진 찍듯이 복사해서 저장소에 보존. 즉 커밋은 작업공간의 어떤 시점의 스냅샷.
   * -m을 통해 editor 실행X.
   * "" 사이에 말을 추가 가능.
* git config
   * 원격 저장소로 데이터를 넘길때 커밋한 사람이 누구며, 어떠한 사람인지 남길 필요가 있다. 이런 인증에 대한 부분을 git config 명령어로 설정.
>* $ g it config --global user.name "sw_hyeonsik" <br>
$ git config --global gustlrehfud@ajou.ac.kr
* git push
   * 현재 프로젝트의 커밋된(HEAD) 내용을 원격 저장소로 내보내는 명령어입니다.
* git mv
   * git에 있는 파일의 이름을 바꾸는 명령어.
* git rm
   * 로컬 디렉토리와 git 저장소 모두에서 파일을 삭제.


### fork, branch 차이점
* fork는 다른 사람의 Github repository에서 내가 어떤 부분을 수정하거나 추가 기능을 넣고 싶을 때 해당 respository를 내 Github repository로 그대로 복제하는 기능이다. <br>
즉 Repository에 권한이 없는 사용자가 저장소를 fork하고 fork한 자신의 저장소에 변경 사항을 적용한 후 Push한다. 이 후 원래 저장소(original repository)에 내 저장소에 있는 브랜치를 Pull Request 한다. 내가 만든 코드가 ok되면 해당 저장소에 Merge 된다. <br>
-> 또 다른 프로젝트를 만들 때 사용.
* 은 특정 repository를 내 local machine에 복사하여 새로운 저장소를 만든다. clone한 원본 repository를 remote 저장소 origin으로 가지고 있다. 권한이 없는 경우 해당 저장소로 push 하지 못한다. <br>
->소규모 팀에서 활용 가능한 예, 프로젝트를 수정할 때 사용.
