import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int weight = scanner.nextInt();
        System.out.println(solver(weight));

    }

    public static String solver(int weight) {
        if (weight <= 3) {
            return("NO");
        }

        if ((weight - 2) % 2 == 0) {
            return("YES");
        } else {
            return("NO");
        }
    }
}
