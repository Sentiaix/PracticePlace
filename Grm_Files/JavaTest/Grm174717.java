// https://level.goorm.io/exam/174717/%ED%81%B0-%EC%88%98%EC%8B%9D-%EC%B0%BE%EA%B8%B0/quiz/1
// Date: 2026-10-04 23:13:13

/*
			  :: 큰 수식 찾기 ::
    '+, -, *'로 이루어진 두 수식 A, B가 주어진다.
    두 수식을 비교해 더 큰 수식의 계산결괏값을 출력하라.

                [수식의 조건]
    수식의 첫 문자/마지막 문자는 항상 숫자이다.
    수의 첫 문자가 0인 경우는 없다.
    수식엔 연산자가 반드시 하나 이상 존재한다.
    연산자가 붙어서 연달아 등장하지 않는다.
    수식에 등장하는 수와 계산값은 abs(10^14) 이하이다.
    수식의 길이는 3이상 20 이하이다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm174717 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        String a = st.nextToken();
        String b = st.nextToken();

        long res_A = calculate(a);
        long res_B = calculate(b);

        System.out.println(res_A < res_B ? res_B : res_A);
    }
    static long calculate(String str) {
        int len = str.length();

        /*
            Operator를 저장하고,
            A oper B를 calc()로 수행하려함.
            그리고 그 값을 A에 다시 저장하고,
            연산자를 읽은 후, 다음 숫자 B를 또 찾음.

            치명적인 실수: 연산 우선순위를 고려하지 않음..
        */

        char oper = '+';

        long result = 0; // +,- 연산이 끝난 값
        long term = 0;   // * 연산을 위해 임시저정하는 곳

        int start = 0; // 마지막으로 문자열을 잘랐던 위치

        for(int i = 0; i < len; i++) {
            char c = str.charAt(i);

            if (isOper(c)) {
                // start ~ (i-1) 까지 숫자
                long num = Long.parseLong(str.substring(start, i));

                if (oper == '+') {
                    result += term;
                    term = num;
                }
                else if (oper == '-') {
                    result += term;
                    term = -num;
                }
                else if (oper == '*') {
                    term *= num;
                }
                
                oper = c;
                start = i + 1;
            }
        }

        // 마지막은 연산자를 만나지 않으므로, 추가 처리 필요함
        // substring(i,j) << python의 list slicing과 같은 구조임.
        long num = Long.parseLong(str.substring(start));

        if (oper == '+') {
                result += term;
                term = num;
            }
            else if (oper == '-') {
                result += term;
                term = -num;
            }
            else if (oper == '*') {
                term *= num;
            }
        
        result += term;

        return result;
    }
    static boolean isOper(char c) {
        if (c == '+' || c == '-' || c == '*') {
            return true;
        }
        else {
            return false;
        }
    }
    // static long calc(long a, long b, char oper) {
    //     // Switch문엔 case마다 break가 있어야하지만,
    //     // return하면 함수가 종료되니까 패스
    //     switch (oper) {
    //         case '+':
    //             return a + b;
    //         case '-':
    //             return a - b;
    //         case '*':
    //             return a * b;            
    //     }
    //     // oper가 + - * 이 아닌 경우
    //     return -1;
    // }
}