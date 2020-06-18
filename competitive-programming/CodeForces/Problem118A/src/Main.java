import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String word = scanner.nextLine();
        System.out.println(new Solver().solve(word));

    }
}

class Solver {
    public String solve(String word) {
        word = word.toLowerCase();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < word.length(); i++) {
            char currChar = word.charAt(i);
            if (currChar == 'a' || currChar == 'e' || currChar == 'i' ||
                    currChar == 'o' || currChar == 'u' || currChar == 'y') {
//                 continue;
            }  else {
                sb.append('.');
                sb.append(word.charAt(i));
            }
        }
        return sb.toString();
    }
}