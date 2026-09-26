// https://level.goorm.io/exam/208968/%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-%EA%B2%8C%EC%9E%84/quiz/1

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 40

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

int factorize(long long* arr, long long n);
void solve();

int main(){
	long long num; // 2-10e11
	if (scanf("%lld", &num) != 1) return 0;

	// int size = (int)sqrt(num); // 10^12의 최대 소인수 갯수는 39개임.
	long long arr[MAX_SIZE];

	factorize(arr, num);


	return 0;
}

int factorize(long long* arr, long long n){
	int idx = 0;
	for (long long d = 2; d <= n / d; d++){
		while(n % d == 0){
			n /= d;
			arr[idx++] = d;
		}
	}
	arr[idx++] = n; // 마지막 남은 인수 추가.

	// for (int i = 0; i < idx; i++){
	// 	printf("%lld", arr[i]);
	// }
}

void solve(){

}