// https://level.goorm.io/exam/173089/%EC%A0%95%EC%88%98%EC%9D%98-%EA%B8%B8%EC%9D%B4/quiz/1

// import java.util.Scanner;
import java.io.*;

public class Grm173089 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // ** String 형은 IMMUTABLE임. **
        String str = br.readLine();

        // String str = "Hello";
        // char[] chars = str.toCharArray();
        // System.out.println(chars[0]); // H

        int len = str.length();

        System.out.println(len);
    }
}