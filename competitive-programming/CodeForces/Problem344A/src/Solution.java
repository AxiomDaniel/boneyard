import java.util.Scanner;

public class Solution {
    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();

        int ans = solve(n);
        System.out.println(ans);
    }

    public static int solve(int n) {
        int currPolarity = scanner.nextInt();
        scanner.nextLine();
        int groups = 1;
        for (int i = 0; i < n-1; i++) {
            int currMagnet = scanner.nextInt();
            scanner.nextLine();

            if (currMagnet != currPolarity) {
                groups++;
                currPolarity = currMagnet;
            }
        }
        return groups;
    }
}
