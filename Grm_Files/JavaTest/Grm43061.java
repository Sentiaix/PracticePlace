// https://level.goorm.io/exam/43061/%EA%B3%84%EC%88%98%EA%B8%B0-%EB%A7%8C%EB%93%A4%EA%B8%B0/quiz/1
// Date: 2026-10-10 23:21:02

/*
                    :: 계수기 만들기 ::
    [ 문제 조건 ]
    계수기를 구현하라. 조건은 아래와 같다.
    - 계수기는 N개의 자릿수를 표현할 수 있다.
    - i번째 자리에는 0부터 Ai까지의 숫자를 표시할 수 있다.
    - 버튼을 누르면 가장 오른쪽 자리의 숫자가 1 증가한다.
        - 만약 어떤 자리의 숫자가 표기최댓값보다 커진다면,
            숫자를 0으로 초기화하고 바로 왼쪽자리 숫자를 1 증가시킨다
        - 가장 왼쪽 칸이 max를 넘으면 왼쪽올림을 전파하지 않는다
    계수기에 표시되는 숫자의 초기 상태가 주어질 때,
    K번 버튼을 누른 뒤 계수기의 상태를 출력하라.

    [ 입력 ]
    첫째 줄에 숫자판의 개수 N이 주어진다.
    둘째 줄에 각 숫자판의 max값 A1, ... , An이 공백을 두고 주어진다.
    셋재 줄에 각 숫자판의 초기값 B1, ... , Bn이 공백을 두고 주어진다.
    넷째 줄에 버튼을 누르는 횟수 K가 주어진다.

    [ 변수 조건 ]
    N (1 - 8) $ Ai(0 - 9) $ Bi (0 - Ai) $ K (0 - 100_000)
    모든 입력은 정수이다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm43061 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        // Sequence A
        int max[] = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++){
            max[i] = Integer.parseInt(st.nextToken());
        }

        // Sequence B
        int init[] = new int[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++){
            init[i] = Integer.parseInt(st.nextToken());
        }

        // K
        int k = Integer.parseInt(br.readLine());

        // Main logic
        // Shift method 안 씀
        for (int i = 0; i < k; i++) {
            int idx = n - 1;

            while (idx >= 0 && init[idx] == max[idx]) {
                init[idx] = 0;
                idx--;
            }

            if (idx >= 0) {
                init[idx]++;
            }
        }

        // 출력
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++){
            if (i > 0) sb.append("");
            sb.append(init[i]);
        }

        System.out.println(sb);
    }
}