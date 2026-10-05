// https://level.goorm.io/exam/175232/%EC%88%AB%EC%9E%90-%EB%B0%B0%EC%97%B4/quiz/1
// Date: 2026-10-04 22:27:48

/*
    n(1-100)이 주어진다.
    n*n 행렬에 자연수의 수열로 채운다.
*/

import java.io.*;

public class Grm175232 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        int arr[][] = new int[n][n];
        int pos = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = pos++;
                System.out.printf("%d", arr[i][j]);
                if ( (j+1) != n ) System.out.printf(" ");
            }
            System.out.println();
        }
    }
}