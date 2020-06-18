import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        scanner.nextLine();
        int[] scores = new int[n];
        for (int i = 0; i < n; i++) {
            scores[i] = scanner.nextInt();
        }
        System.out.println(new Solver().solve(n, k, scores));
    }
}

class Solver {
    public static int solve(int n, int k, int[] scores) {
        int nextRound = 0;
        for (int i = 0; i < n; i++) {
            if (scores[i] >= scores[k -1] && scores[i] > 0) {
                nextRound ++;
            } else {
                break;
            }
        }
        return nextRound;
    }
}