import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();
        System.out.println(solve(n));
    }

    private static int solve(int n) {
        Integer[] coins = new Integer[n];

        for (int i=0; i < n; i++) {
            coins[i] = scanner.nextInt();
        }

        Arrays.sort(coins, Collections.reverseOrder());

        int currSum = 0;
        int sum = 0;
        for (int coin : coins) {
            sum += coin;
        }

        int numCoins = 0;
        while (currSum <= sum) {
            currSum += coins[numCoins];
            sum -= coins[numCoins];
            numCoins++;
        }
        return numCoins;
    }
}
