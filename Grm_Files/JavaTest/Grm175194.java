// https://level.goorm.io/exam/175194/%EA%B5%AC%EB%A6%84-%EC%8A%A4%ED%80%98%EC%96%B4/quiz/1
// Date: 2026-10-03 22:34:38

/*
    행새의 개수 N(1-200_000)이 주어진다.
    각 행사는 시작 시간과 끝나는 시간이 주어지고, 일정이 겹치면 안 된다.
    행사가 끝나고 시작하는 동안 1시간의 준비시간(공백)이 필요하다.
    위의 조건을 따르면서 가장 많이 열수 있는 행사의 수를 출력하라.
*/

import java.io.*;
import java.util.*;

public class Grm175194 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1-200_000
        int n = Integer.parseInt(br.readLine());

        Schedule[] sch = new Schedule[n];
        
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            sch[i] = new Schedule(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken())
            );
        }

        int result = Scheduler(sch, n);

        System.out.println(result);
    }
    static class Schedule {
        int s_time;
        int e_time;
        int duration;

        Schedule(int s, int e) {
            this.s_time = s;
            this.e_time = e;
            this.duration = e - s;
        }
    }

    /*
                        :: 로직 유의사항 ::
        1. 하나 선택하면 같은 s_time을 공유하는 케이스를 검증하지 않음.
            단, duration까지 고려 한 상태여야 함.
        2. 
    */
    static int Scheduler(Schedule[] sch, int n) {
        /*
                        :: 정렬 선택지 ::

            1. 시작 타임 순 정렬 [ 보류 ]
             >> 언제 시작하는지로 따져볼 수 있음.
             로직 예) s_time 순서 중, duration이 짧은 순서로 체크

            2. 엔드 타임 순 정렬 [ 선택 ]
             >> 가장 많이 꺼내려면 "언제 끝나는가"를 봐야 함.

            3. druation 순 정렬 [ 보류 ]
             >> 빠르게 꺼낼 수 있음.
             로직 예) duration이 작은 순으로 정렬, s_time이 빠른 순으로 채택
                      물론 추가 작업이 있어야 함.
        */

        // e_time 오름차순 정렬
        Arrays.sort(sch, (a, b) -> Integer.compare(a.e_time, b.e_time));

        int max_held = 0;
        int cur_eTime = -1;

        /*
            Python의 for문처럼 선형 자료구조에 있는
            객체들을 꺼내서 호출 할 수 있음.
        */
        for (Schedule s: sch) {
            if (s.s_time > cur_eTime) {
                max_held++;
                cur_eTime = s.e_time;
            }
        }

        return max_held;
    }
}