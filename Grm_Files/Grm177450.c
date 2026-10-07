// https://level.goorm.io/exam/177450/%EB%B3%B4%EB%93%9C-%EA%B2%8C%EC%9E%84/quiz/1
// Date: 2026-10-06 21:46:52


/*
			:: 보드게임 구현 ::
	[ 문제 조건 ]
	0번 칸부터 N번까지 N+1칸짜리 보드 위에서
	말 하나를 움직여 N번째 칸에 말을 이동시키는 게임이다.

	말은 1칸 or 3칸만 이동가능하며, 보드 밖으로는 못 나간다.
	규칙에 따라 이동가능한 경우의 수를 출력하시오
	(단, 1_000_000_007로 경우의 수를 나눈 나머지를 출력하라)

	[ 입력 ]
	첫째 줄에 N이 주어진다.

	[ 변수 조건 ]
	N (1 - 100_000)
*/

/*
	DP(Dynamic Programmig)문제
	>> DP: 전에 했던 작업을 기억함으로써
		   최적 "부분" 동작을 구현해내는 방법.

	N번째 칸에 도달하는 방법
	>> 1. N-1번째 칸에서 1칸 이동.
	>> 2. N-3번째 칸에서 3칸 이동.

	즉, n번째 칸에 도달하는 경우는
	f(n) = f(n-1) + f(n-3)
	으로 표현 가능하며.

	따라서 i번째 칸에 도달하는 경우는
	f(i) = f(i-1) + f(i-3)
	으로 표현 가능하다.

// https://www.youtube.com/watch?v=0bqfTzpWySY

*/
#include <stdio.h>

#define MOD 1000000007
#define MAX_N 100000

int main(){
	int n = 0;
	scanf("%d", &n);

	long long dp[MAX_N + 1] = {0};

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];

		if (i >= 3) {
			dp[i] = (dp[i] + dp[i - 3]) % MOD;
		}
	}
	
	printf("%lld\n", dp[n]);
	
	return 0;
}