// https://level.goorm.io/exam/174702/a-b/quiz/1

import java.io.*;
import java.util.StringTokenizer;

public class Grm174702 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        
        System.out.println(a + b);
    }
}

/* 
        :: Python ::
a,b = map(int, input().split())
print(a + b)

           :: C ::
#include <stdio.h>

int main(){
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    return 0;
}

WTF TS JAVA IS FUCKING TRASH LANGUAGE
*/