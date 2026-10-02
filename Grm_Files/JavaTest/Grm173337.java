// https://level.goorm.io/exam/173337/8%EC%A7%84%EC%88%98-%EA%B3%84%EC%82%B0%EA%B8%B0/quiz/1

/*
    n개의 10진수를 모두 더하고, 8진수로 출력하기.
*/

import java.io.*;
import java.util.StringTokenizer;


public class Grm173337 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int result = 0;

        for (int i = 0; i < n; i++) {
            result += Integer.parseInt(st.nextToken());
        }

        System.out.printf("%s%n", Integer.toOctalString(result));
    }
}