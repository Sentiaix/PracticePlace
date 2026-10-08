// https://level.goorm.io/exam/177478/%EB%AD%89%EC%B9%9C-k/quiz/1
// Date: 2026-10-07 20:50:00

/* 
                    :: 뭉친 K 구하기 ::
    [ 문제 조건 ]
    N*N 2차원 배열 M에서, i번째줄 j번째칸의 값을 M(i,j)라고 한다.
    배열 M에는 뭉친 그룹이 있다. 이는 상화좌우(대각X)로 인접한 칸으로
    연결되어 있으며, 그 그룹의 속한 칸의 개수와 같다.

    M(x,y)칸의 값이 K일 때, 값이 K인 칸으루 이루어진 뭉친 그룹의 
    가장 큰 뭉친 그룹 사이즈를 출력하시오.

    [ 입력 ]
    첫째 줄에 M의 크기 N이 주어진다.
    둘째 줄에 x,y가 공백을 두고 주어진다.
    다음줄부터 N개의 줄동안 M의 상태가 주어진다.

    [ 변수 조건 ]
    N (1 - 500) $ x,y (1 - N) $ M(i,j) (0 - 9)
    (단, 모든 수는 정수이다.)
*/

/*
    DP문제 2.
    4       
    1 2     
    0 0 1 1 
    0 1 1 0 
    0 0 0 1 
    1 1 1 1 
*/

import java.io.*;
import java.util.*;

public class Grm177478 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());

        int matrix[][] = new int[n][n];
        boolean visited[][] = new boolean[n][n];
        visited[row - 1][col - 1] = true;

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            
            for (int j = 0; j < n; j++){
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int target = matrix[row - 1][col - 1];
        int max = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == target && visited[i][j] == false) {
                    int size = DFS(matrix, visited, i, j, target);
                    max = Math.max(max, size);
                }
            }
        }

        System.out.println(max);
    }
    static int DFS(int matrix[][], boolean visited[][], int row, int col, int k) {
        // boolean visited[][] = new boolean[n][n];
        visited[row][col] = true;

        int count = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++){
            int nx = row + dx[d];
            int ny = col + dy[d];

            // 범위 밖이면 무시하기
            if (nx < 0 || nx >= matrix.length ||
                ny < 0 || ny >= matrix[0].length) {
                    continue;
            }
            
            // K가 아니거나 이미 방문 시 표기
            if (matrix[nx][ny] != k || visited[nx][ny] == true) {
                continue;
            }

            count++;
        }
        
        return count;
    }
}