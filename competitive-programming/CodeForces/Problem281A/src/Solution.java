import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String input = scanner.nextLine();
        if (input.length() < 1) {
            System.out.println(input.toUpperCase());
        } else {
            String output = input.substring(0, 1).toUpperCase() + input.substring(1);
            System.out.println(output);
        }
    }
}
