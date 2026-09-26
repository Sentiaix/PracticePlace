// https://level.goorm.io/exam/208968/%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-%EA%B2%8C%EC%9E%84/quiz/1
// I'm listning to"ド屑" now.

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 40

// Best(N) > 입력에 N이 주어지므로 N을 소인수분해함.
// 큰 순서대로 정렬하면 가장 큰 숫자가 탄생.
// Best(M) > ??

// qsort를 사용하여 글자 대조
//     int compare(const void* a, const void* b){
//     int x = *(const int*)a;
//     int y = *(const int*)b;

//     char xy[32];
//     char yx[32];

//     snprintf(xy, sizeof(xy), "%d%d", x, y);
//     snprintf(yx, sizeof(yx), "%d%d", y, x);

//     return strcmp(yx, xy);
// }

void factorize(long long* arr, long long n);
void bestM(long long* arr, long long n);

int main(){
	long long num; // 2-10e11, 성현이의 숫자
	if (scanf("%lld", &num) != 1) return 0;

	// 특수케이스 제거
	if (num == 2){
		printf("3\n");
		return 0;
	}

	// int size = (int)sqrt(num); // 10^12의 최대 소인수 갯수는 39개임.
	long long arr_n[MAX_SIZE];
	long long arr_m[MAX_SIZE];

	factorize(arr_n, num);
	bestM(arr_m, num);


	return 0;
}

void factorize(long long* arr, long long n){
	int idx = 0;
	for (long long d = 2; d <= n / d; d++){
		while(n % d == 0){
			n /= d;
			arr[idx++] = d;
		}
	}
	if ( n > 1 ) arr[idx++] = n; // 마지막 남은 인수 추가.

	// test print
	printf("BEST N IS : ");
	for (int i = 0; i < idx; i++){
		printf("%lld", arr[i]);
	}
	printf("\n");
}

void bestM(long long* arr, long long n){
	if (n == 2) {
		arr[0] = 1;
		return;
	}

	int idx = 0; // 반환할 배열의 idx
	long long m = 1; // min(N) == 2, min(m) == 1

	// 1. 일단 2로 한자리 빼고 가득 채움.
	while(m * 2 <= n / 2){
		m *= 2;
		arr[idx++] = 2;
	}
	
	// 2. 마지막 자리가 3이 될 수 있다면 3 채택. 어차피 5,7은
	// 2*2보다 더 작으므로 무의미
	if (m * 3 < n){
		arr[idx++] = 3;
		m *= 3;
	}
	else{
		arr[idx++] = 2;
		m *= 2;
	}

	// test print
	printf("BEST M IS : ");
	for (int i = 0; i < idx; i++){
		printf("%lld", arr[i]);
	}
	printf("\n");

	// else{
	// 	printf("ERROR!\n");
	// 	return;
	// }
	
	return;
}