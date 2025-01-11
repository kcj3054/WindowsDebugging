﻿// SampleCode.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 원하는 라인에 f9를 눌렀다가 땠다가하면 브레이크 포인트, on off 걸린다.
// 

// condition break.
//  -> 메모리 상태가변하거나, 조건이 맞을 때 들어옴
//  -> 멀티스레드 환경일 때 condition break를 사용할 때 해당 지점에 각기 다른 스레드가 들어올 때 마다 브레이킹이 걸릴 수 있다. 
//          -> (Filter 부분) 그럴 때 condition filter에 ThreadID = '원하는 아이디'라고 조건을 걸면된다. 
//   -> Filter말고, Action 부분에 원하는 message도 출력할 수 있다.
//  -> 
int main()
{

   /* int* ptr = nullptr;
    *ptr = 100;*/

    /*
    AeDebug 설정 (자동 디버깅)
    - 어플리케이션이 크래시하면 즉시 디버거로 연결가능.
    - visual studio에서 실행 시 크래쉬나오면 디버깅 연결이 되지만, exe 같은것은 바로 죽어버릴 수 있다. 이럴 때 유용함 
    - Release 빌드 디버깅에 유용함
    - Release 빌드 + Page Heap 디버깅에 유용함
    - 멀트프로세스 디버깅에 유용함
        - 부모 -> 자식에있을 때 
       -> 설정해도 동일하게 .exe가 바로 죽어버리네 ;;  이유가 궁금하다 , 도구 옵션에서 디버깅 옵션도 다 활성화되어있다.
    [설정방법]
        - 
   */
    /*
    * 환경구축 권장사항
    * - 해당 빌드의 소스코드, exe, dll, lib, pdb 파일들을 보관해 둘 것, 
    * - 위 사항대로해야 나중에 dump 파일 수집했을 때 디버깅이 가능하다 
    */

    /*
    * 조사식에 포인터 대상으로 디버깅 꿀팁 
    * - int* p = new int[10];
    *    for(int i = 0 ; i < 10; i++) ... 일 때 조사식에 p,10으로하면 p 배열 다 볼 수 있음;;
    */

    int* p = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        p[i] = i;
    }

    /*
    * parallel watch 
    * - 스레드별로 자신의 threadindex를 보여준다. 
    * - 병렬스택과 다른건가??, 스레드별로 자신의 변수들을 다 볼수 있따.
    * - 
    */
    /*
    * parallel stack
    * - 이게 병렬 스택;
    * - debug -> window -> parallel stack 
    * - 데드락 발생시 유용하다, 어떤 스레드가 어디에있는지 볼 수있어 유용하다,,,
    * - 이것도 실습해보면 좋다..
    */

    /*
    * 
    * - disassemly 항상 켜둔다, 디버깅과 학습에 유용하다 
    * - c++코드에 대응되는 어셈블리 코드를 보여준다,
    * - 릴리즈빌드에서는 최적화되어서, 디버깅하기가 어렵다 
    *      - 결과적으로 어셈없으면 디버깅하기 어렵다.. 
    *      - 
    * - 디버그 -> 창 -> dissembly 
    * - srw lock 성능 분석도 디스어셈블리로 확인했다고한다.. 
    */

    /*
    * 
    * [heap profile]
    * 
    * - 
    * 
    */

    /*
    * [dump 파일]
    * - procdump -> 
    * - processdump, dump파일 저장
    * - dump 파일 생성 코드 작성
    *    - 
    * - 덤프파일 생성 부분에서 createfile을 사용하는 이유는.. crt 메모리 손상에서 cwrite쪽 손상이 올 수도있다???
    * - 
    */

    /*
    * [windbg]
    * - ms에서 제공하는 windows용 전문 debugger, user mode/kernel mode 디버깅 지원
    * - 전문 디버거라서 visualstudio ui보다 불편함
    * - vs의 기능으로 충분치 않을 경우 heap 디버깅등 windbg 사용.
    * - sdk로는 노출되지 않는 구조체 형식도 windbg에서 확인가능 ??? 
    */

    /*
    * heap curruption이 도대체 머지?
    * - 힙깨먹는거???, 이게 메모리 깨먹는거랑 비슷한건가??
    * - 
    */
}


/*
* CInventory* pInventory = GetMap()->GetPlayerCharacter()->GetInventory();

위코드는 디버깅 시 용이한 코드가 아니고, 굉장히 불편함 어디 Get에서 문제가 발생했는지 알 수 없음
물론 f11로 타고들면서 디버깅을해도되긴하다. 그렇지만 한 화면에서 보는 것이 아니니 당연히 더 불편하다.. 

CMap* pMap = GetMap();
CPlayerCharacter* pPlayer~ = pMap->GetPlayerCharacter() ~ 이런 것이 더 편하다. 

- c#에서는 첫번째 문제가 되는 상황이라도 디버깅이 가능하지만 c++은 지원을 안해준다. ㅠㅠ

- int* p = new int[10];
 for(int i = 0 ; i < 10; i++)
 {
    p[i] = i;
 }

 - watch(조사식)에서 rax(레지스터)값을 보기도하네?..

 - @err,hr 이 GetLastError를 조사식에서 볼 수 있는 것이다. 
 - 
**
*/

/*
* pdb , symbol 설정 .. 
* 
* 
*/

/*
* [분산락]
* 
* - 분산락이란 여러 서버(프로세스)가 공유 데이터를 제어하기 위한 기술이다.
* - https://velog.io/@a01021039107/%EB%B6%84%EC%82%B0%EB%9D%BD%EC%9C%BC%EB%A1%9C-%ED%95%B4%EA%B2%B0%ED%95%98%EB%8A%94-%EB%8F%99%EC%8B%9C%EC%84%B1-%EB%AC%B8%EC%A0%9C%EC%9D%B4%EB%A1%A0%ED%8E%B8 
* 해당 링크 설명대로라면 분산락 == 락인데 ? 
* 
* 
* - 레디스에서 분산락을 많이 지원한다, 그렇지만 socket서버에서는 redis를 안쓰는 경우도 많아서 분산락을 사용할 일이없을 수도있다.
* - 또한 분산락이라는 것이, 다수의 서버가 동시에 같은 자원에 접근할 때 발생할 수 있는 동시성 문제를 해결하기 위해 사용되는 동기화 매커니즘이다. 
* - 게임 실시간 서버라면 그럴필요가없다 A게임월드를 담당하는 전용 A gameDB가 존재하기에, b게임월드에서 A gameDB에 접근할 필요가 없다..
*   - 또한 락을 처리할 때 db 전용 스레드들을 따로 돌리기때문에, ,.. DB전용 큐도 존재하기에 상관할 필요가 없다. 
* - 분산락의 핵심은 "하나의 자원에 하나의 서버만 작업을 수행할 수 있다"
*   - 하나의 자원에 하나의 스레드만 작업을 수행할 수 있다도 맞는 말일까 ? 
* 
* - 위 나의 궁금증을 잘 해결해주는 영상이다. https://www.youtube.com/watch?v=rdbCwjct7h0
* 
* - 
*/

/*
* select ... for update  
*  - 행 단위로 동시 접근 제어.
*  - 먼저 락을 구한 커넥션은 실행 지속, 락을 구하지 못한 커넥션은 락을 구한 커넥션이 트랜잭션을 종료할 때까지 대기. 
*  - 위 쿼리를 사용하면 간단하게 동시 수정을 막을 수 있음
*  - 외부의 별도 프로세스(REDIS) 필요 없음 
*  - 주의할 점은 데드락, 시간초과가 발생할 수 있음 // spinlock 사용하면 되겠구먼.. 
*  - 
* 
* 
* - 단일 프로세스
*   - 메모리에서 Lock으로 제어
*   - 파일을 Lock으로 쓰기 
* 
* - 다중 프로세스 
*   - 레디스 같은 외부 프로세스를 활용
*   - DB가 제공하는 기능을 사용 
* 
* 
* - 선점해서막기 (pessimistic)
*   - 먼저 접근 권한 얻으면 수정 가능 
* 
* - 뒤에 수정하면 막기 (optimistic)
*   - 먼저 수정한 것을 반영 (버전 칼럼 등 활용)
* 
* - 출처 :  https://www.youtube.com/watch?v=rdbCwjct7h0
* 
* - cf :  웹같은 경우에는 여러 프로세스 (여러 휴대폰으로 ) 동일 이벤트를 동시에 누를 수 있음 , 게임서버는 로그인 단에서 1개의 단말만 접속가능하기에
* 전혀다르다. 
* 
*/