import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();
        int currCapacity = 0;
        int maxCapacity = 0;
        int a;
        int b;
        for (int i = 0; i < n; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            currCapacity -= a;
            currCapacity += b;
            if (currCapacity > maxCapacity) {
                maxCapacity = currCapacity;
            }
        }
        System.out.println(maxCapacity);

    }
}

