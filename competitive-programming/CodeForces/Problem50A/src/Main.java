import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int m = scanner.nextInt();
        int n = scanner.nextInt();

        int totalArea = m * n;
        System.out.println(totalArea/2);
    }
}
