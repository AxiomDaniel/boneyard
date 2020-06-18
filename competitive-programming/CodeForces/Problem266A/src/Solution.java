import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();
        String input = scanner.nextLine();
        System.out.println(new Solver().solve(n, input));
    }
}

class Solver {
    public int solve(int n, String input) {
        int count = 0;
        for (int i = 0; i < n -1; i++) {
            if (input.charAt(i) == input.charAt(i + 1)) {
                count++;
            }
        }
        return count;
    }
}