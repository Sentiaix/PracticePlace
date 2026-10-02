// https://level.goorm.io/exam/175880/%ED%81%B0-%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC/quiz/1

/* 
        ::인스선트 메서드와 정적 메서드::

    1. (Instant) method:
     - 일반 메서드는 객체에 의존하게 설계되는지를 보고
       판단하면 된다. (이 코드에선 "br"쯤이 객체가 될 수 있음)

    2. static method:
     - 정적 메서드는 객체에 묶인게 아닌, Class에 묶인
       경우에 이용하는 메서드 형식이다.
       메서드가 객체의 상태와 관련없이 작동할 경우에 쓴다.
*/

import java.io.*;

public class Grm175880 {

    static final long MOD = 1_000_000_007L;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Long number = Long.parseLong(br.readLine());

        // long result = factorial(number) % MOD;

        System.out.println(factorial(number));
    }
    static long factorial(long n) {
        if (n == 1) return 1;
        
        // 재귀함수좀 쓰려했더니만 바로 StackOverFlow
        // return n * factorial(n-1) % MOD;

        long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result * i) % MOD;
        }

        return result;
    }
}