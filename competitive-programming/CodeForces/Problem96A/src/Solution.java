import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        String input = scanner.nextLine();
        System.out.println(new Solver().solve(input));
    }
}

class Solver {
    public String solve(String input) {
        int count = 1;
        char currChar = input.charAt(0);
        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == currChar) {
                count++;
            } else {
                count = 1;
                currChar = input.charAt(i);
            }

            if (count >= 7) {
                return("YES");
            }
        }
        return("NO");
    }
}
