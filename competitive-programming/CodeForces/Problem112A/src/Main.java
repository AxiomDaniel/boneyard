import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String first = scanner.nextLine();
        String second = scanner.nextLine();

        if (first.compareToIgnoreCase(second) > 0) {
            System.out.println(1);
        } else if (first.compareToIgnoreCase(second) < 0) {
            System.out.println(-1);
        } else {
            System.out.println(0);
        }
    }
}
