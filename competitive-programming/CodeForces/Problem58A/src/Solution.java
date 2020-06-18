import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String input  = scanner.nextLine();
        System.out.println(solve(input));
    }

    public static String solve(String input) {
        int currIndex = 0;
        String hello = "hello";
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == hello.charAt(currIndex)) {
                currIndex++;
            }

            if (currIndex >= 5) {
                return "YES";
            }
        }
        return "NO";
    }
}
