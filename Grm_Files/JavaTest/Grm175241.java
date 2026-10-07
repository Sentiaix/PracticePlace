// https://level.goorm.io/exam/175241/queue/quiz/1
// Date: 2026-10-05 23:05:23

/*
                  :: Queue 자료구조 구현하기 ::
    [ 조건 ]
    주어지는 명령은 [push]와 [pop]이다.
    [push]는 Queue에 크기가 1인 정수를 추가하는 명령이다.
    만약 Queue가 가득 찼는데 [push]를 명령한다면, Overflow를 출력한다.
    [pop]은 Queue에서 추가된지 가장 오래된 정수를 제거하고,
    제거된 숫자를 출력하는 명령이다.
    만약 Queue가 비어있을대 [pop]을 명령하면, Underflow를 출력한다

    [ 입력 ]
    첫째 줄에는 명령의 개수 N과 Queue의 크기 K가 공백을 두고 주어진다.
    push 명령은 push <value>구조를, pop은 pop 구조를 따른다.

    [ 변수 조건 ]
    N (1 - 100_000) $ K (1 - 1_000) $ <value> (1 - 100)
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm175241 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken()); // 실행할 명령 수
        int k = Integer.parseInt(st.nextToken()); // Queue의 크기

        int queue[] = new int[k];

        // 명령 입력
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            String command = st.nextToken();

            // String은 **객체** 라서 == 연산자를 쓰는건
            // 같은 **String** 객체인지 확인을 하는것이 됨
            if (command.equals("push")) {
                int value = Integer.parseInt(st.nextToken());
                push(queue, value);
            }
            else if (command.equals("pop")) {
                pop(queue);
            }
        }
    }
    static void push(int arr[], int value) {
        int size = arr.length;

        // 마지막 칸이 안비었는데 작업을 수행하려 하면 Overflow리턴
        if (arr[size - 1] != 0) {
            System.out.println("Overflow");
            return;
        }

        // 뒤에서부터 다음칸에 값 옮기기
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;

        return;
    }
    static void pop(int arr[]) {
        int size = arr.length;

        // Queue가 비어있는데 호출됐다면 Underflow 리턴
        if (arr[0] == 0) {
            System.out.println("Underflow");
            return;
        }

        // 마지막 값 꺼내기
        for (int i = size - 1; i >= 0; i--) {
            if (arr[i] != 0) {
                System.out.println(arr[i]);
                arr[i] = 0;
                return;
            }
        }
    }
}