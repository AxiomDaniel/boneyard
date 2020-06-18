import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        long n = scanner.nextInt();
        long m = scanner.nextInt();
        long a = scanner.nextInt();
        System.out.println(solver(n,m,a));
    }

    public static long solver(long n, long m, long a) {
        return ((long) (Math.ceil((double) n/a) * Math.ceil((double) m / a)));
    }
}
