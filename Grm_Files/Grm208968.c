// https://level.goorm.io/exam/208968/%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-%EA%B2%8C%EC%9E%84/quiz/1
// I'm listning to"ド屑" now.

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 40

// Best(N) > 입력에 N이 주어지므로 N을 소인수분해함.
// 큰 순서대로 정렬하면 가장 큰 숫자가 탄생.
// Best(M) > 2로 모두 다 채우고, 마지막에 3이 들어갈수 있는지 판단.
// 2^k이냐 2^(k-1)*3이냐 차이.

void factorize(char* str, long long n);
void bestM(char* str, long long n);
void arr_to_str(long long* arr, int idx, char* str);
int compare(const void* a, const void* b);
void str_add(const char* a, const char* b, char* result);

int main(){
	long long num; // 2-10e11, 성현이의 숫자
	if (scanf("%lld", &num) != 1) return 0;

	// 특수케이스 제거
	if (num == 2){
		printf("3\n");
		return 0;
	}

	char str_n[100];
	char str_m[100];
	char result[201];

	factorize(str_n, num);
	bestM(str_m, num);

	str_add(str_n, str_m, result);

	printf("%s\n", result);

	return 0;
}

void factorize(char* str, long long n){
	long long arr[MAX_SIZE]; // MAX_SIZE is 40

	int idx = 0;
	for (long long d = 2; d <= n / d; d++){
		while(n % d == 0){
			n /= d;
			arr[idx++] = d;
		}
	}
	if ( n > 1 ) arr[idx++] = n; // 마지막 남은 인수 추가.

	// // test print
	// printf("BEST N IS : ");
	// for (int i = 0; i < idx; i++){
	// 	printf("%lld", arr[i]);
	// }
	// printf("\n");

	qsort(arr, idx, sizeof(long long), compare);

	arr_to_str(arr, idx, str);

	return;
}

void bestM(char* str, long long n){
	long long arr[MAX_SIZE];

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
	// 2*2보다 더 작으므로 무의미( 4 < 5,7 < 8 )
	if (m * 3 < n){
		arr[idx++] = 3;
		m *= 3;
	}
	else{
		arr[idx++] = 2;
		m *= 2;
	}

	// // test print
	// printf("BEST M IS : ");
	// for (int i = 0; i < idx; i++){
	// 	printf("%lld", arr[i]);
	// }
	// printf("\n");

	qsort(arr, idx, sizeof(long long), compare);

	arr_to_str(arr, idx, str);
	
	return;
}

//								v size v
void arr_to_str(long long* arr, int idx, char* str){
	int pos = 0; // str의 현재 위치/길이 를 저장하는데 씀.

	for (int i = 0; i < idx; i++){
		pos += sprintf(str + pos, "%lld", arr[i]);
	}
	str[pos] = '\0';
}

int compare(const void* a, const void* b){
    long long x = *(const int*)a;
    long long y = *(const int*)b;

    char xy[32];
    char yx[32];

    snprintf(xy, sizeof(xy), "%lld%lld", x, y);
    snprintf(yx, sizeof(yx), "%lld%lld", y, x);

    return strcmp(yx, xy);
}

#include <string.h>

void str_add(const char* a, const char* b, char* result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int carry = 0;

    char temp[100];

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // temp는 거꾸로 저장되어 있으므로 뒤집기
    for (int x = 0; x < k; x++)
        result[x] = temp[k - 1 - x];

    result[k] = '\0';
}
