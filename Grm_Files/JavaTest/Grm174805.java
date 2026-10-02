// https://level.goorm.io/exam/174805/%EC%88%AB%EC%9E%90-%EC%A0%9C%EA%B1%B0-%EB%B0%B0%EC%97%B4/quiz/1

/* 
    숫자 N(1-100_000)과 K(1-100)이 첫 줄에 주어짐
    두번째줄에 N개의 숫자(a(1-200_000))들을 받음.

    각 a들 문자열안에 K가 들어있지 않은 숫자의 갯수를 구하기
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm174805 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        String k = st.nextToken();

        StringTokenizer numbers = new StringTokenizer(br.readLine());

        int count = 0;

        for (int i = 0; i < n; i++) {
            String a = numbers.nextToken();

            // String a 안에 문자열 k가 포함되어 있지 않은지 탐색
            if (!a.contains(k)) {
                count++;
            }
        }

        System.out.println(count);
    }
}