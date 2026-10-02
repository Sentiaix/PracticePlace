// https://level.goorm.io/exam/174704/a-b-2/quiz/1

import java.io.*;
import java.util.StringTokenizer;

public class Grm174704 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // StringTokenizer string을 parsing해서 하나씩 쪼개둠.
        StringTokenizer st = new StringTokenizer(br.readLine());

        double a = Double.parseDouble(st.nextToken());
        double b = Double.parseDouble(st.nextToken());

        System.out.printf("%.6f%n", a + b);
    }
}