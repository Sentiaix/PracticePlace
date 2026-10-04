// https://level.goorm.io/exam/175177/%EA%B1%B0%EC%8A%A4%EB%A6%84-%EB%8F%88/quiz/1
// Date: 2026-10-03 23:05:45

import java.io.*;

/*
            :: 거스름 돈 구하기 ::
    1 | 5 | 10 | 20 | 40 단위의 화폐가 있다.
    금액 N(1-10^9)이 주어졌을때, 화폐를 가장 적게
    사용하여 거스름돈을 표현해라.
*/

public class Grm175177 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int charge = Integer.parseInt(br.readLine());

        int amount = 0; // 출력될 화폐의 수

        // Same as in Python 'for coin in [40, 20, 10, 5, 1]'
        for (int coin: new int[]{40, 20, 10, 5, 1}) {
            amount += charge / coin; // 자바는 소숫점을 자동으로 버림
            charge %= coin;
        }

        System.out.println(amount);
    }
}