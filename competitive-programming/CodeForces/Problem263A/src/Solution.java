import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(solve());
    }

    public static int solve() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int value = scanner.nextInt();
                if (value == 1) {
                    return calcSwaps(i, j);
                }
            }
            scanner.nextLine();
        }
        return -1;
    }

    public static int calcSwaps(int row, int col) {
        return Math.abs(row - 2) + Math.abs(col - 2);
    }
}
