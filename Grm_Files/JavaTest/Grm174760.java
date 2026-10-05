// https://level.goorm.io/exam/174760/%EB%8B%A8%EC%96%B4-%ED%95%84%ED%84%B0/quiz/1
// Date: 2026-10-04 22:27:40

/*
                :: 단어 필터 만들기 ::
	첫째 줄에 검열할 단어 S의 길이와
	수신한 메세지 E의 길이가 공백을 두고 주어진다.

	둘째 줄에 단어 S가, 마지막 줄엔 메세지 E가 주어진다.

	이때 메세지 E에 검열단어 S가 포함된 경우,
	메세지 E에서 단어 S만 제거한 후 남은 글자들만 출력한다.

	(1 - S - E - 10_000), S와 E는 알파벳 대소문자만 사용한다.
*/

import java.io.*;
import java.util.StringTokenizer;

public class Grm174760 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 단어 S의 길이, 메세지 E의 길이 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s_size = Integer.parseInt(st.nextToken());
        int e_size = Integer.parseInt(st.nextToken());

        // 단어 S, 메세지 E 입력
        String s = br.readLine();
        String e = br.readLine();

        /*
            E에서 S를 제거했는데, aacc > a[ac]c > ac 이런식으로
            또 생기는 경우를 제거해야한다.

            사실 Stringbuilder를 이용하면 더 논리적으로 정리할 수 있는데
            어차피 CodeTest는 제한 안에 통과만 하면 그만.
        */
        for(int i = 0; i < 10_000; i++) {
            if (e.length() <= s.length()) break;
            e = e.replace(s, "");
        }

        if (e.length() == 0) {
            System.out.println("EMPTY");
            return;
        }

        System.out.println(e);
    }
}