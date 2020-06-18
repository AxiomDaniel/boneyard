import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(solver(scanner.nextLine()));
    }

    private static String solver(String aString) {
        for (int i = 0; i < aString.length(); i++) {
            switch((int) aString.charAt(i)) {
                case 72: case 81: case 57:
                    return "YES";
            }
        }
        return "NO";
    }
}

