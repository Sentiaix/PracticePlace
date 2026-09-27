// https://level.goorm.io/exam/47882/%ED%97%B7%EA%B0%88%EB%A6%AC%EB%8A%94-%EC%9E%91%EB%8C%80%EA%B8%B0/quiz/1
// <div class="d590a451cc5502a925429b4aabde134f" role="region" aria-label="일반 콘텐츠 영역"><p><span style="font-size: 24px;"><span style="font-weight: bolder;">문제</span></span></p><hr><p><span style="font-size: 0.875rem;">문자 중에는 서로 비슷하게 생겨서 구분하기 힘든 문자들이 있다. 대표적으로 숫자&nbsp;<code style="font-size: 12.25px;">0</code>&nbsp;과 알파벳&nbsp;<code style="font-size: 12.25px;">O</code>&nbsp;가 그렇다. 또 다른 구별하기 힘든 문자로는 작대기 모양의 문자들이 있다. 숫자&nbsp;<code style="font-size: 12.25px;">1</code>, 알파벳 대문자&nbsp;<code style="font-size: 12.25px;">I</code>, 알파벳 소문자&nbsp;<code style="font-size: 12.25px;">l</code>, 그리고 or 기호&nbsp;<code style="font-size: 12.25px;">|</code>&nbsp;는 모두 비슷하게 생겼다.</span><br></p><p>서로 비슷하게 생긴 문자열은 코딩을 할 때나 글을 작성할 때 쉽게 구분이 가지 않아 번거롭다. 문자열이 주어졌을 때, 그 문자열 안에 들어있는&nbsp;<span style="font-size: 0.875rem;"><code style="font-size: 12.25px;">1</code>,&nbsp;<code style="font-size: 12.25px;">I</code>,&nbsp;<code style="font-size: 12.25px;">l</code>,&nbsp;<code style="font-size: 12.25px;">|</code>&nbsp;의 개수를 구해보자.</span></p><p><br></p><p><span style="font-size: 24px;"><span style="font-weight: bolder;">입력</span></span></p><hr><p><span style="font-size: 0.875rem;">첫째 줄에 </span>문자열이 주어진다.</p><ul><li>주어지는 문자열의 길이는 <span><img src="/texconverter?eq=1"></span> 이상 <span><img src="/texconverter?eq=5%5C%2C000"></span> 이하이다.</li><li>주어지는 문자열은 알파벳 대소문자와 공백 문자, 그리고&nbsp;<code style="font-size: 12.25px;">(</code>,&nbsp;<code style="font-size: 12.25px;">!</code>,&nbsp;<code style="font-size: 12.25px;">@</code>,&nbsp;<code style="font-size: 12.25px;">#</code>,&nbsp;<code style="font-size: 12.25px;">$</code>,&nbsp;<code style="font-size: 12.25px;">|</code>,&nbsp;<code style="font-size: 12.25px;">)</code>&nbsp;특수 문자로만 이루어져 있다.</li><li>주어지는 문자열의 첫 번째 문자와 마지막 문자가 공백 문자인 경우는 주어지지 않는다.</li></ul><p><br></p><p><span style="font-size: 24px;"><span style="font-weight: bolder;">출력</span></span></p><hr><p>네 개의 줄에 걸쳐, 주어진&nbsp;<span style="font-size: 0.875rem;">문자열 안에 들어있는&nbsp;</span><span style="font-size: 0.875rem;"><code style="font-size: 12.25px;">1</code>,&nbsp;<code style="font-size: 12.25px;">I</code>,&nbsp;<code style="font-size: 12.25px;">l</code>,&nbsp;<code style="font-size: 12.25px;">|</code>&nbsp;의 개수를 한 줄에 하나씩 출력한다.</span></p></div>
// 쉬어가는 문제

// -- 문제 --
// 문자열이 주어지고, 거기서 1 i l | 을 찾아 순서대로
// 각 줄에 출력한다. 문자열 범위는 1-5000자이다.

#include <stdio.h>
#include <string.h>

int main(){
    char str[5001];
    int found[4] = {0,}; // 1 I l | 순서임.

    scanf("%5000[^\n]", str); //5000글자 + 개행입력 전까지만 읽음
    int len = strlen(str);

    for (int i = 0; i < len; i++){
        switch (str[i])
        {
        case '1':
            found[0]++;
            break;
        case 'I':
            found[1]++;
            break;
        case 'l':
            found[2]++;
            break;
        case '|':
            found[3]++;
            break;            
        default:
            break;
        }
    }

    for (int i = 0; i < 4; i++){
        printf("%d\n", found[i]);
    }    

    return 0;
}