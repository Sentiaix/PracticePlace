// https://level.goorm.io/exam/194193/%EC%86%8C%EA%B8%88%EB%AC%BC%EC%9D%98-%EB%86%8D%EB%8F%84-%EA%B5%AC%ED%95%98%EA%B8%B0/quiz/1
// Date: 2026-10-10 22:52:49

/*
                :: 소금물의 농도 구하기 ::
    [ 문제 조건 ]
    7% 소금물 N(g)이 있다. 이 소금물에 M(g)만큼의 물을 넣었을 때,
    소금물의 농도를 표현하시오. (소숫점 2자리까지 표현, 나머지 버림)

    [ 입력 ]
    첫째 줄에 정수 N과 M이 공백을 두고 주어진다.

    [ 변수 조건 ]
    N,M (100 - 100_000)
*/

#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    // concentration
    // 농도 = 소금의 양 / 소금물의 양
    double c = (7.0 * n) / (n + m);

    printf("%.2f", (int)(c * 100) / 100.0f);

    return 0;
}