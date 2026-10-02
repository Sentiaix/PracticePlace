// https://level.goorm.io/exam/174732/%EB%8C%80%EC%86%8C%EB%AC%B8%EC%9E%90-%EB%B0%94%EA%BE%B8%EA%B8%B0/quiz/1

// https://tangoblog.tistory.com/14

import java.io.*;
// import java.util.Scanner;

public class Grm174732 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Scanner sc = new Scanner(System.in);

        // int n = sc.nextInt();       // len 입력, scanner 사용

        int n = Integer.parseInt(br.readLine());

        String str = br.readLine(); // bufferedReader는 String만 읽어짐

        // String은 immutable 형식자이므로, 배열로 변환해서 수정
        char[] arr = str.toCharArray();

        // array length
        // int len = arr.length;

        for (int i = 0; i < n; i++) {
            if ('a' <= arr[i] && arr[i] <= 'z') {
                arr[i] += 'A' - 'a'; // 0x20 차이 (32 차이)
            }
            else if ('A' <= arr[i] && arr[i] <= 'Z') {
                arr[i] -= 'A' - 'a';
            }
            System.out.printf("%c", arr[i]);
        }

        /* 
            위 방식 말고도 char c = str.charAt(i)으로
            한글자씩 받아서 비교/출력 하는 방법이 있음. 이게 더 빠름
        */
        
        System.out.printf("%n");
    }
}