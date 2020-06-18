import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        for (int i = 1; i < n + 1; i++) {
            if (checkLucky(i)) {
                if (n % i == 0) {
                    System.out.println("YES");
                    System.exit(0);
                }
            }
        }
        System.out.println("NO");
    }

    public static boolean checkLucky(int x) {
        String number = Integer.toString(x);
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) != '4' && number.charAt(i) != '7') {
                return false;
            }
        }
        return true;
    }
}
