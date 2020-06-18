import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String input = scanner.nextLine();
        System.out.println(new Solver().solve(input));
    }
}

class Solver {
    public String solve(String input) {
        ArrayList<String> charList = new ArrayList<String>();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) != '+') {
                charList.add(Character.toString(input.charAt(i)));
            }
        }
        Collections.sort(charList);
        return String.join("+", charList);
    }
}