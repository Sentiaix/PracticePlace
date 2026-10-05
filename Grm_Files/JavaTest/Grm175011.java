// https://level.goorm.io/exam/175011/0-%EC%B1%84%EC%9A%B0%EA%B8%B0/quiz/1
// Date: 2026-10-04 22:57:06

/*
            :: 0 바꾸기 ::
    n * n 배열 중간에 0이 하나 있다.
    0을 기준으로 같은 열 | 같은 행의 수들을
    모두 더해서 0대신 입력하려고 한다.

    이때 교체될 값을 출력하라.

    첫 줄에 n이 주어지고, 둘째줄부터 크기에 맞게
    0 한개를 포함한 n * n 배열에 들어갈 값이 주어진다.

    n(3-100), 원소들은 1_000 이하의 정수
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm175011 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int matrix[][] = new int[n][n];
        
        // 0의 좌표를 저장함
        int row = 0;
        int col = 0;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            for (int j = 0; j < n; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                if (matrix[i][j] == 0) {
                    col = j;
                    row = i;
                }
            }
        }
        
        int sum = 0; // 0의 자리에 들어갈 값 저장
        for (int i = 0; i < n; i++) {
            sum += matrix[row][i]; // 가로줄 값 합하기
            sum += matrix[i][col]; // 세로줄 값 합하기
        }

        System.out.println(sum);
    }
}