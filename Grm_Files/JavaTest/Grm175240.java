// https://level.goorm.io/exam/175240/stack/quiz/1
// Date: 2026-10-08 23:33:14

/*
            :: Stack 자료구조 구현 ::

	[ 문제 조건 ]
	크기가 K인 Stack 자료구조를 구현하라.
	주어지는 명령은 [push]와 [pop]이다.
	[push]는 Stack에 크기가 1인 정수를 추가한다.
	만약 Stack이 가득 차 있으면 Overflow를 출력한다.
	[pop]은 Stack에서 가장 최근에 추가된 정수를
	제거하고, 제거된 정수를 출력한다.
	만약 Stack이 비어있다면 Underflow를 출력한다.

	[ 입력 ]
	첫째 줄에는 명령의 개수 N과 스택의 크기 K를 공백을 두고 주어진다.
	그 다음 줄부터는 N개의 명령이 주어진다.
	push <value> : 스택에 값이 <value>인 정수를 추가한다.
	pop : Stack에서 가장 최근에 추가된 정수를 제거한다.

	[ 변수 조건 ]
	N (1 - 100_000) $ K (1 - 1_000) $ <value> (1 - 100)
	주어진 수는 모두 정수이다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm175240 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int stack[] = new int[k];

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            
            String command = st.nextToken();

            if (command.equals("push")) {
                int value = Integer.parseInt(st.nextToken());
                push(stack, value);
            }
            else if (command.equals("pop")) {
                pop(stack);
            }
        }
    }

    /*
        배열이 [  |  |  |  |  |  |  ] 처럼 생겼을때.
        맨 아래< ------------------ > 맨 위
        처럼 취급할것임.
    */
    static int index = 0; // 공용인덱스 설정

    static void push(int stack[], int value) {
        final int TOP = stack.length;
        if (stack[TOP] != 0) {
            System.out.println("Overflow");
            return;
        }

        stack[index] = value;
        index++;
        return;
    }
    static void pop(int stack[]) {
        final int BOTTOM = 0;
        if (stack[BOTTOM] == 0) {
            System.out.println("Underflow");
            return;
        }

        index--;
        System.out.println(stack[index]);
        stack[index] = 0;
        return;
    }
}