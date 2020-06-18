import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.nextLine();
        int ones = 0;
        int twos = 0;
        int threes = 0;
        int fours = 0;
        for (int i = 0; i < n; i++) {
            int number = scanner.nextInt();
            switch(number) {
                case 1:
                    ones++;
                    break;
                case 2:
                    twos++;
                    break;
                case 3:
                    threes++;
                    break;
                case 4:
                    fours++;
                    break;
            }
        }
        // Counting for groups of four
        int total = fours;

        // Pairing 3s and 1s
        if (threes > ones) {
            total += ones;
            threes -= ones;
            ones = 0;
        } else {
            total += threes;
            ones -= threes;
            threes = 0;
        }

        // Convert the ones into 2s
        twos += ones / 2;
        ones = ones % 2;

        // Pairing the groups of 2s into one taxi
        total += twos / 2;
        twos = twos % 2;

        // Pair the 1s and 2s
        if (ones > twos) {
            total += twos;
            ones -= twos;
            twos = 0;
        } else {
            total += ones;
            twos -= ones;
            ones = 0;
        }

        // Add the remaining 2s and 3s
        total += twos;
        total += threes;

        // Add the remaining 1s;
        total += ones / 4;
        if (ones % 4 > 0) {
            total += 1;
        }

        System.out.println(total);
    }
}
