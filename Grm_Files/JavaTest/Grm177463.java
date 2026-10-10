// https://level.goorm.io/exam/177463/rgb-%EC%A3%BC%EC%B0%A8%EC%9E%A5/quiz/1
// Date: 2026-10-09 15:39:08

/*
                :: 칸 색칠하기 ::
    수직선 모양의 N칸으로 이루어진 바닥을
    빨/파/초 3색으로 색칠한다고 할 때,
    인접한 색으로 칠하지 않고 바닥을 모두
    색칠할 수 있는 경우의 수를 구하시오.

    (단, 출력은 100_000_007로 나눈 나머지를 출력하라)
        
    [ 입력 ]
    첫째 줄에 주차장의 크기 N이 주어진다.

    [ 변수 조건 ]
    N (1 - 10_000)
*/

/*
    DP 문제 2.

    처음 색을 R로 가정하면,
    그 다음 칸은 G,B
    G랑 B에서 각각 뻗을 수 있는 경우의 수는
    G >> R,B
    B >> R,G
    총 4가지. 다해서 6
    R > G,B > R,B | R,G > ...
    전 상태에서 다음 상태가 2배로 늘어나므로
    F(n) = F(n-1) * 2
    와 같은 점화식을 구할 수 있음.
*/

import java.io.*;

public class Grm177463 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        long count = 3;
        long next = 0;
        final long MOD = 100_000_007L;

        for (int i = 2; i <= n; i++){
            next = count * 2;
            count = next % MOD;
        }

        System.out.println(count);
    }
}