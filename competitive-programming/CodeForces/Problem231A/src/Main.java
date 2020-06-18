import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();
        int solvable = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            sum += scanner.nextInt();
            sum += scanner.nextInt();
            sum += scanner.nextInt();
            scanner.nextLine();

            if (sum >= 2) {
                solvable++;
            }
        }
        System.out.println(solvable);
    }
}