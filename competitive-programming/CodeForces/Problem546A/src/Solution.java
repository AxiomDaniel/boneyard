import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        int w = scanner.nextInt();

        int totalW = (w * (w + 1)) / 2;
        int totalCost = totalW * k;
        if ((totalCost - n) > 0 ) {
            System.out.println(totalCost - n);
        } else {
            System.out.println(0);
        }
    }
}
