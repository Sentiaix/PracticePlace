// https://level.goorm.io/exam/348291/%EC%9D%B4%EC%96%B4-%EB%B6%99%EC%9D%B4%EA%B8%B0/quiz/1

// Solution
// 두 카드 A,B에 쓰인 숫자들을 a,b라 할 때,
// ab > ba 를 판단한다.

// a와 b를 문자열로 바꿈. (ab, ba는 무조건 자릿수가 a + b사이즈로 같음)
// strcmp등 문자열 비교를 해서 ASCII비교를 수행.
// ㄴ 첫 글자가 같으면, 다음글자 ASCII 비교 하는 방식.
// snprintf(ab, sizeof(ab), "%s%s", str1, str2)식 정렬 가능성

// -- 만약 qsort를 사용한다면.. (pivot 위치조정함수) --
// int compare(const void *a, const void *b)
// {
//     int x = *(int *)a;
//     int y = *(int *)b;

//     if (x < y) return -1;
//     if (x > y) return 1;
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b); // qsort에 사용될 비교함수

int main(){
	int n; // 1 - 10,000
	if (scanf("%d", &n) != 1) return 0;

	int cards[n]; // 0 - 10e8
	for (int i = 0; i < n; i++){
		scanf("%d", &cards[i]);
	}

	int zero_cnt = 0; // 0 세기
	// 여기에 제로를 다 찾고 0 0 0 0 0인 케이스를 찾아서 0을 출력하도록 하기

	// 합칠때 큰 순으로 정렬
	qsort(cards, n, sizeof(int), compare);

	// qsort로 큰 순으로 정렬했음에도
	// 가장 큰 수가 0으로 시작하는 경우를 제거.
	if(!cards[0]){ // 10으로 나눠져서 0이면, -1뱉고 종료
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n; i++){
		printf("%d", cards[i]);
	}
	printf("\n");

	return 0;
}

// int를 str로 바꿔서 한글자씩 ASCII를 비교하고,
// 누가 더 큰지 반환함
int compare(const void* a, const void* b){
	int x = *(const int*)a;
	int y = *(const int*)b;

	char xy[32];
	char yx[32];

	snprintf(xy, sizeof(xy), "%d%d", x, y);
	snprintf(yx, sizeof(yx), "%d%d", y, x);
	
	return strcmp(yx, xy);
}
// [ 폐기한 아이디어 ]
// Solution
// 1. 앞자리가 큰 순서대로 배치. 
// 예: 31, 591, 92 >> 92, 591, 31
// (단, 맨 앞자리가 같으면 순차적으로 그 다음 자리도 확인해야함)
// 예2: 35, 359, 3951 >> 3951, 359, 35
// 2. 정렬된 순서대로 이어붙임.
// 예: 9259131
// 3. 정수(0~10e8)가 쓰인 n개(1-10000)의 카드를 조합해 가장 큰 숫자 완성

/* 숫자 크기 정렬 규칙
1. 첫 머릿글자가 큰 순서대로 정리한다.
2. 머릿글자가 같으면, 두 번째 글자도 확인한다.
   (최대 글자길이 9. Max O(N) is O(9))
   (최대 연산횟수 10000 * 9 = 90 000)
3. 두번째, 세번째, ... , 끝까지 확인한 후 순서대로 새 배열에 저장한다.
4. 새 배열의 내용을 모두 string으로 전환 후 한 줄의 str으로 만든다.
5. 마지막 string을 atoi로 바꿔 출력한다 */
// ^^ 아이디어 기각. 10,000 * 10e8 >> 9만자리 숫자 발생.. 어느 size의 char로도 감당불가