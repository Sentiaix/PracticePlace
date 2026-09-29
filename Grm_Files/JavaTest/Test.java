// 자바도 해야지..

public class Test{
    public static void main(String[] args){
        System.out.println("Hello java");
        int arr[];
        arr = new int[5];
        arr[0] = 3;
        for (int i = 1; i < 4; i++){
            arr[i] = i;
        }


        System.out.println("\nI'll print alphabets.\n");
        String[] alphabet = {"A", "B", "X", "Z"};

        for (String alpha : alphabet){
            System.out.println(alpha);

            if (alpha == "X") break;
        }
    }
}

// Class의 상속 등 해야할게 주구장창