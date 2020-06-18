import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int x = 0;
        int y = 0;
        int z = 0;

        int n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < n; i++) {
            x += scanner.nextInt();
            y += scanner.nextInt();
            z += scanner.nextInt();
            scanner.nextLine();
        }
        if (x == 0 && y == 0 && z == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
