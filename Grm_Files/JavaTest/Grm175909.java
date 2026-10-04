// https://level.goorm.io/exam/175909/%EC%B9%B4%EB%93%9C-%EB%AA%A8%EC%9C%BC%EA%B8%B0/quiz/1

/*
	N종의 카드가 있다. M장의 카드들이 순서대로 제공되고,
	이 카드들을 수집해 N종의 카드를 모두 모으면 된다.
	[ 1 <= N, M <= 1_000_000 ]
	첫줄에 N, M이 주어지고 각 줄마다 카드가 주어진다.
	줄의 순서대로 카드를 받을 수 있고, N종의 카드가
	다 모이는 최소 장수를 출력하고, M장을 모두 받아도
	불가능하다면 -1을 출력한다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm175909 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 입력
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());


        boolean collected[] = new boolean[n + 1]; // 전부 false가 기본값
        int count = 0;                            // 카드의 종류 출력.

        for (int i = 0; i < m; i++) {
            int card = Integer.parseInt(br.readLine());

            if (collected[card] == false) {
                collected[card] = true;
                count++;
            }

            if (count == n) {
                // 현재 0부터 시작해 i번째 idx를 탐색했으므로 i + 1
                System.out.println(i + 1);
                return;
            }
        }

        System.out.println("-1");
    }
}