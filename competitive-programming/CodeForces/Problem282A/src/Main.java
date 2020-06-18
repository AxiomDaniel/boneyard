import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();

        int x = 0;
        for (int i = 0; i < n; i++) {
            String statement = scanner.nextLine();
            if (statement.charAt(0) == '+' || statement.charAt(2) == '+') {
                x++;
            } else if (statement.charAt(0) == '-' || statement.charAt(2) == '-') {
                x--;
            } else {
                System.out.println("Error");
            }
        }
        System.out.println(x);
    }
}
