#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000 // 1,000,000,000

// 두 값 중 작은 값을 반환
#define min(x, y) ((x) < (y) ? (x) : (y))


// from 온도에서 to 온도로 바꾸는 최소 버튼 횟수
//
// 온도는 0 ~ 9이고 원형으로 연결되어 있다.
//
// 예)
// 2 -> 5 : 3번
// 2 -> 9 : 3번 (2 -> 1 -> 0 -> 9)
//
int change_cost(int from, int to) {
	int diff = abs(from - to);

	// 정방향으로 가는 경우: diff
	// 반대 방향으로 돌아가는 경우: 10 - diff
	return min(diff, 10 - diff);
}


int dist(int* arr, int n);


int main() {
	int n;
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d\n", dist(arr, n));

	return 0;
}


int dist(int* arr, int n) {

	/*
		인덕션은 3개이므로 하나의 상태를
		(a, b, c)
		형태로 생각할 수 있다.

		예를 들어
		(a, b, c) = (1, 2, 3)이면

		1번 인덕션의 온도 = 1
		2번 인덕션의 온도 = 2
		3번 인덕션의 온도 = 3

		이다.
	*/

	/*
		dp[10][10][10]으로도 똑같이 만들 수 있음.

		dp[a][b][c]
		= 인덕션 온도가 (a, b, c)일 때의 최소 버튼 횟수

		하지만 이것을 1차원으로 압축해서
		dp[1000] 으로 사용함.
	*/

	/*
		(a, b, c)를 숫자 하나로 바꾸는 방법

		(a, b, c)
		→ a * 100 + b * 10 + c

		예)
		(1, 2, 3) → 123
		(4, 5, 6) → 456
		(9, 8, 7) → 987

		따라서 dp[123] 은

		"인덕션 온도가 (1, 2, 3)인 상태" 를 의미하게 됨.
	*/

	int dp[1000];
	int next[1000];

	// 아직 도달하지 않은 상태는 INF로 설정
	for (int i = 0; i < 1000; i++) {
		dp[i] = INF;
	}


	/*
		처음에는 인덕션 3개 모두 온도가 0이다.
		(a, b, c) = (0, 0, 0) 이것을 숫자로 표현하면
		0 * 100 + 0 * 10 + 0 = 0

		따라서 dp[0] = 0 이다.
	*/

	dp[0] = 0;

		// 음식을 하나씩 처리한다.
		// arr[i] = 이번 음식에 필요한 온도
	for (int i = 0; i < n; i++) {

		int target = arr[i];


		/*
			next는 "이번 음식을 처리하고 난 뒤의 상태"를 저장한다.

			매 음식마다 새로 계산하기 때문에
			일단 모든 값을 INF로 초기화한다.
		*/
		for (int j = 0; j < 1000; j++) {
			next[j] = INF;
		}


			// 현재 가능한 모든 상태를 확인한다.
		for (int state = 0; state < 1000; state++) {

			// 이 상태에 도달할 수 없다면 건너뛴다.
			if (dp[state] == INF) {
				continue;
			}


			/*
				state에서 a, b, c를 다시 꺼낸다.
				예를 들어 state = 123이라면
				a = 123 / 100 = 1

				b = (123 / 10) % 10
				  = 12 % 10
				  = 2

				c = 123 % 10
				  = 3

				즉

				123 -> (1, 2, 3)
			*/
			int a = state / 100;
			int b = (state / 10) % 10;
			int c = state % 10;


			/*
				1. 이미 필요한 온도가 있는 경우				
				
				예를 들어 현재 상태가
				(1, 5, 7) 이고 target이 5라면

				2번 인덕션이 이미 5이므로
				버튼을 누를 필요가 없다.

				즉 cost 그대로 유지.
			*/
			if (a == target || b == target || c == target) {

				int next_state = a * 100 + b * 10 + c;

				next[next_state] =
					min(next[next_state], dp[state]);
			}


				// cost 변수명을 계속 새롭게 쓰기 위해서
				// packaing을 함.
				// 2. 1번 인덕션을 target으로 변경
				// (a, b, c) -> (target, b, c)
			{
				int cost = change_cost(a, target);

				int next_state =
					target * 100 + b * 10 + c;

				next[next_state] =
					min(next[next_state],
						dp[state] + cost);
			}

				// 3. 2번 인덕션을 target으로 변경
				// (a, b, c) -> (a, target, c)
			{
				int cost = change_cost(b, target);

				int next_state =
					a * 100 + target * 10 + c;

				next[next_state] =
					min(next[next_state],
						dp[state] + cost);
			}

				// 4. 3번 인덕션을 target으로 변경
				// (a, b, c) -> (a, b, target)
			{
				int cost = change_cost(c, target);

				int next_state =
					a * 100 + b * 10 + target;

				next[next_state] =
					min(next[next_state],
						dp[state] + cost);
			}
		}

		// 	이번 음식까지 처리했으므로
		// 	next → dp 로 넘긴다.

		// 	다음 음식은 이번 음식까지 처리한 상태에서 시작함.
		for (int j = 0; j < 1000; j++) {
			dp[j] = next[j];
		}
	}


	// [모든 음식이 끝난 경우]
	// 어떤 최종 상태에 있든 상관없으므로
	// 모든 dp 중 최솟값을 찾는다.

	int answer = INF;

	for (int i = 0; i < 1000; i++) {
		answer = min(answer, dp[i]);
	}

	return answer;
}