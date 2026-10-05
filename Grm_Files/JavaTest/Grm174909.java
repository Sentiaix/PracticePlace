// https://level.goorm.io/exam/174909/m%EB%B0%B0-%EB%B0%B0%EC%97%B4/quiz/1
// Date: 2026-10-05 22:21:54

/*
					:: M배 배열 만들기 ::
    배열의 모든 원소가 M으로 나누어떨어지면 M배 배열이다
    나누어 떨어지지 않는 원소에는 M을 곱하고, 아니면 그냥 둔다.

    M배 배열이 된 배열 A를 순서대로 출력하라.

    첫줄에 원소의 수 N과 배율 M이 주어진다.
    다음 줄에 배열 A가 주어진다.

    N (1 - 100_000) $ M (1 - 1_000) $ A (1 - 100_000)
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm174909 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine()); // 재호출

        // 배열도 필요 없음
        // int arr[] = new int[n];

        int num = 0;
        
        for (int i = 0; i < n; i++) {
            num = Integer.parseInt(st.nextToken());

            if (num % m != 0) {
                num *= m;
            }
            
            System.out.print(num);
            if (i != n) System.out.print(' ');
        }

        System.out.println();
    }
    // // 배열을 M배 배열로 바꾸는 함수 를 만들려고 했는데 굳이 필요가 없음
    // static void makeMultipleArray(int[] arr, int m) {
    //     int len = arr.length;
    //     for (int i = 0; i < len; i++) {
    //         if (arr[i] % m != 0) {
    //             arr[i] *= m;
    //         }
    //     }
    // }
}