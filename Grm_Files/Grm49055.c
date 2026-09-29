// https://level.goorm.io/exam/49055/%EC%88%98%EC%97%B4%EC%9D%98-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98/quiz/1

/*               -- 문제 --
    N개의 정수로 이루어진 수열의 모둔 수에 대한 최대공약수를 구함.
    수열중 몇 개의 수를 제거해, 더 큰 최대공약수를 구하려함.
    더 큰 최대공약수(Greatest Common Divisor)를 구할 수 있는 최솟값은?
*/

/*               -- 조건 --
    첫재 줄에 수열의 길이 N: 2 - 300 000가 주어지고
    둘째줄부터 각 정수 A(1-10^7)이 주어짐.
    최소로 수를 지우는 횟수를 출력하고
    어떤 수를 지우던 GCD가 변치않는다면 -1 리턴.
*/

/*
    1. 수열을 받고 GCD를 구하는 함수를 구현.
     1-1) Divisors를 구하는 함수를 구현한다.
     1-2) 만약 수열에 수정이 가해졌다면, 
          제거한 수를 기반으로 GCD를 재탐색해
          costs를 절약한다.
    2. 제거하는 경우의 수를 구현
     2-1) 소수, 공약수가 적은 수 등..
     2-2) 경우를 판단한다.
          큰 수들 대비 작은수가 있는 경우,
          그 수들은 건들 필요 X
*/

#include <stdio.h>
#include <stdlib.h>

int get_GCD(int a, int b);

int main(){
    int n; // 1 - 300 000
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);


    /*
        1. 모든 수들의 GCD를 구하기.
          입력을 받으며 모든 수들의 GCD를 구함
    */
    int gcd = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        gcd = get_GCD(gcd, arr[i]);
    }

    /*
        2. 모든 수를 GCD로 나누고 새로운 수열을 정의.
    */
    int max_v = 0; // 최적화를 위해 가장 큰 값을 기억.
    
    for (int i = 0; i < n; i++){
        arr[i] /= gcd;
        if(arr[i] > max_v) max_v = arr[i];
    }

    // 1,1,1,1...같은 max value가 1인경우 -1리턴
    if (max_v == 1){
        printf("-1\n");
        free(arr);
        return 0;
    }

    /*
        3. SPF(가장작은 소수인 약수)찾는 알고리즘 이용
        spf[x] <- x의 가장 작은 약수 저장
    */
    int* spf = (int*)calloc(max_v + 1, sizeof(int));

    // 에라토스테네스의 체 이용.
    // 간단히 설명하면 최소로직으로 소수집합을 생성하여
    // 조금 더 최적화된 소수들로의 연산을 함
    for (int i = 2; i <= max_v; i++){
        if (spf[i] != 0) continue;

        spf[i] = i; // i는 소수임.

        if ((long long)i * i <= max_v){
            for (int j = i * i; j <= max_v; j += i){
                if(spf[j] == 0){ // 현재 가장 작은 소수가 기록되지 않았다면,
                    spf[j] = i; // i가 가장 작은 소인수임.
                }
            }
        }
    }

    /*
        4. count[d] 설정
        ^^ d를 약수로 가지는 수 저장
    */
    int* count = (int*)calloc(max_v + 1, sizeof(int));

    /*
        5. 모든 수에 대한 모든 약수 생성
    */
    for (int i = 0; i < n; i++){
        int x = arr[i];

        // 10^7 이하에서 약수 많아봐야 1000개
        int divs[1000];

        int divs_cnt = 1; // 현재 만들어진 약수의 수
        divs[0] = 1;      // 처음 약수는 1만 존재함.

        while (x > 1){
            int p = spf[x];
            int exponent = 0; // 지수(exponent)
            
            while (x % p == 0){
                x /= p;
                exponent++;
            }
            /*
                만들어진 약수의 개수.

                ex) 현재 약수:
                    1, 3
                    p = 2, exponent = 2
                    >> 2, 6
                    >> 4, 12
            */
            int old_num = divs_cnt;
            int power = 1;
            for (int e = 1; e <= exponent; e++){
                power *= p;
                
                for (int j = 0; j < old_num; j++){
                    divs[divs_cnt++] = divs[j] * power;
                }
            }
        }
        
        for (int j = 1; j <= divs_cnt - 1; j++){
            count[divs[j]]++;
        }
    }

    free(arr); // arr 정리

    /*
        6. 가장 많이 공유하는 약수 찾기
        예: X가 가장 많이 공유된 수임

        그럼 X를 안가지고 있는 숫자를
        수열에서 제거한다면 조건을 달성함.
    */
    int max_cnt = 0; // 가장 많이 나온 수 저장
    
    for (int d = 2; d <= max_v; d++){
        if (count[d] > max_cnt){
            max_cnt = count[d];
        }

        /*
            모든 숫자가 d의 배수인 경우.
            처리 없이 0회로 결과가 나오는 케이스임.

            앞에서 처리한 CASE(모두 1인 경우)에 속하는 상황이라
            처리할 필요가 없지만, 부분적으로 이해를 위해 남겨둠.
        */
        if (max_cnt == n) break;
    }


    /*
        7. 정리 후 출력
    */
    if (max_cnt == 0){ // 출력할게 없는 경우
        printf("-1\n");
    }
    else {
        printf("%d\n", n - max_cnt);
    }

    free(count);
    free(spf);

    return 0;
}

/*
        ::유클리드 호제법::
    
    a = bq + r 일 때,
    a와 b의 GCD는 b와 r의 GCD와 같다.

    두 수 a, b에서 a mod b를 시행한다.
    나머지 r이 존재한다면, a = b, b = r을 시행.
    r이 0이 된다면, 마지막 b는 a와 b의 GCD
*/
int get_GCD(int a, int b){
    while (b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}