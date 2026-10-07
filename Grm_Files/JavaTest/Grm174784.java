// https://level.goorm.io/exam/174784/%EB%B0%80%EB%8F%84-%EC%A0%95%EB%A0%AC/quiz/1
// Date: 2026-10-05 23:43:42

/*
            :: 가장 밀도가 높은 물질 구하기 ::
	[ 조건 ]
	N개의 물질 중에서 가장 밀도가 높은 물질을 찾으려 한다.
	밀도는 " 밀도 = 무게 / 부피 " 공식을 따른다.

	가장 밀도가 높은 물질의 번호를 출력하라.

	[ 입력 ]
	첫째 줄에 물질의 개수 N이 주어진다.
	다음부터 물질의 무게 w와 부피 v가 공백을 두고 주어진다.

	[ 변수 조건 ]
	N (1 - 100_000) $ w (1 - 100_000) $ v (1 - 10_000)
    입력에서 주어지는 모든 수는 정수이다.

    Density 밀도, weight 무게, Volume 부피

	/* 개 씨 발 GITHUB 로그인 또 풀렸어 :):):):):):) */


import java.io.*;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int maxIdx = 1;
		int maxV = 1;
		int maxW = 0;
		
        for (int i = 0; i < n; i ++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int w = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

			/*
				Density = w / v;
				MAX W / MAX V < w / v 이면 그게 MAX Density
				양변에 (MAX V)(v) 곱하기
				MAX W * v < w * MAX V
			*/
			if ((long) w * maxV > (long) v * maxW) {
				maxV = v;
				maxW = w;
				maxIdx = i; // i로 대입하고, 결과에서 +1 할 것임.
			}
			// 밀도가 같다면, 무게순
			else if ((long) w * maxV == (long) v * maxW) {
				if (w > maxW) {
					maxW = w;
					maxV = v;
					maxIdx = i;
				}
			}
			
			
        }

        System.out.println(maxIdx + 1);
    }
}