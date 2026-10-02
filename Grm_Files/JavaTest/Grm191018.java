// https://level.goorm.io/exam/191018/%EA%B5%AC%EB%A6%84-%EC%95%84%EC%9D%B4%EB%8F%8C/quiz/1

/* 
    지원자의 수 N(1-100_000)이 주어지고
    다음줄부터 지원자가 받은 점수들 
    S(1-2N)이 주어진다고 할 때,

    상위 3명의 지원자 점수를 출력하시오.
*/

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Grm191018 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        Student[] std = new Student[n];     // n size의 Student 클래스를 호출함.
        for (int idx = 0; idx < n; idx++) { // std[i]에 클래스의 형식에 맞게 값을 대입함.
            std[idx] = new Student(         // 입력받은 score, index
                     Integer.parseInt(st.nextToken()),
                     idx
            );
        }

        /* 
            내림차순으로 정렬
            [152][52][23][12][6]...
        */
        // lambda식. lambda = (입력 변수들) -> 실제 실행할 작업.
        Arrays.sort(std, (a, b) -> b.score - a.score);


        for (int i = 0; i < 3; i++) {
            if ( n <= i ) break;
            System.out.printf("%d ", std[i].index + 1);
        }

        System.out.println();
    }
    static class Student {
        int score;
        int index;

        Student(int score, int index) {
            this.score = score;
            this.index = index;
        }
    }
}