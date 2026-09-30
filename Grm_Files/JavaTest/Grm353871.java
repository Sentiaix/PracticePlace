// https://level.goorm.io/exam/353871/%EB%93%B1%EB%B3%80%EC%82%AC%EB%8B%A4%EB%A6%AC%EC%9D%98-%EB%86%92%EC%9D%B4/quiz/1

import java.util.Scanner;

public class Grm353871 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double k = sc.nextDouble();
        int d1 = sc.nextInt();
        int d2 = sc.nextInt();

        double s = (d2 - d1) / 2.0;
        double hh = (k * k) - (s * s);

        System.out.printf("%.4f%n", hh * 4);

        sc.close();
    }
}