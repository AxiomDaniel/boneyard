import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] lookUp = new int[26];
        String input = scanner.nextLine();
        for (int i = 0; i < input.length(); i++) {
            if (lookUp[(int) input.charAt(i) - 97] == 0) {
                lookUp[(int) input.charAt(i) - 97] = 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (lookUp[i] == 1) {
                sum++;
            }
        }
        if (sum % 2 == 0) {
            System.out.println("CHAT WITH HER!");
        } else {
            System.out.println("IGNORE HIM!");
        }
    }
}
