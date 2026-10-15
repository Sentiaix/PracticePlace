// https://level.goorm.io/exam/167345/%EB%8B%A8%ED%92%8D%EB%82%98%EB%AC%B4/quiz/1
// Date: 2026-10-13 20:50:42

/*
                    :: 단풍나무 물들이기 ::
    [ 문제 조건 ]
    N x N 크기의 공원에 단풍나무가 심어져 있다.
    각 구역 (i, j)에는 아직 물들지 않은 단풍나무가 S[i][j]그루 있다.

    단풍나무는 아래 규칙에 따라 물든다.

    S[i][j]가 0이면 해당 구역의 모든 단풍나무가 물들었음을 의미한다.
    매일 밤, 각 구역의 단풍나무 수는

    상하좌우 인접한 구역 중 그날 아침 기준으로 모든 단풍나무가 물든 구역의 수만큼 감소한다.

    감소량이 현재 단풍나무 수보다 크면 0으로 설정한다.
    모든 구역의 단풍나무가 물들 때까지 걸리는 날짜를 출력한다.

    [ 입력 ]
    첫째 줄에 공원의 크기 N이 주어진다.
    다음 N개의 줄에 각 구역의 단풍나무 수
    S[i][1], ... , S[i][N]이 주어진다.

    [ 변수 조건 ]
    N (1 - 40) $ S[i][j] (0 - 10)
    모든 입력은 정수이다. 모든 단풍나무가 물든 구역이 최소 한 곳 이상 존재한다.
*/

/*
    임의의 칸 A 상하좌우로 모든 물들은 칸의 갯수만큼
    A칸의 물들지 않은 나무가 물들음.
    예: A칸엔 4개의 나무가 물들지 않음. + 상하좌우 3개의 0이 있음
        >> 다음날 아침 A칸의 값은 1이 됨.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm167345 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 공원 크기 입력
        int n = Integer.parseInt(br.readLine());
        // System.out.println("n is: " + n); // debug print
        
        // 공원 상태 입력
        int parts[][] = new int[n][n];
        for (int i = 0; i < n; i++){
            // System.out.println("I is : " + i); // debug print
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < n; j++){
                parts[i][j] = Integer.parseInt(st.nextToken());
                // System.out.println("**" + parts[i][j] + "**"); // debug print
            }
        }

        int result = uncolored_trees(parts);

        System.out.println(result);
    }
    static int uncolored_trees(int mat[][]) {
        int len = mat[0].length;
        int days = 1; // 첫쨋날은 조건에 맞게 물드는 날임

        while (true) {
            // 당일 아침. 모든 단풍이 물들었는지 확인
            boolean allColored = true;
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (mat[i][j] > 0) {
                        allColored = false;
                        break;
                    }
                }
                if (!allColored) break;
            }

            if (allColored) break;

            int next[][] = new int[len][len];
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (mat[i][j] > 0) {
                        allColored = false;
                        next[i][j] = mat[i][j] - chk_nearby(mat, i, j);
                        if (next[i][j] < 0) next[i][j] = 0;
                        // mat[i][j] -= chk_nearby(mat, i, j);
                        // if (mat[i][j] < 0) mat[i][j] = 0; // 음수가 들어가면 0으로 교체
                    }
                }
            }

            // 전체갱신(날짜갱신, 동시성확보)
            for (int i = 0; i < len; i++) {
                System.arraycopy(next[i], 0, mat[i], 0, len);
            }

            days++;
        }

        return days;
    }
    // 근처 상하좌우에 있는 0의 수를 세고, 그 갯수만큼(+) 리턴함
    static int chk_nearby(int mat[][], int x, int y) {
        int offset = 0;
        int max_len = mat[0].length;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];

            if ((0 <= nr && nr < max_len) && (0 <= nc && nc < max_len)) {
                if (mat[nr][nc] == 0) offset++;
            }
        }

        return offset;
    }
}