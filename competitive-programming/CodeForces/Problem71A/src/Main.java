import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        ArrayList<String> array = new ArrayList<String>();
        int n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < n; i++) {
            String temp = scanner.nextLine();
            if (temp.length() > 10) {
                temp = compressString(temp);
            }
            array.add(temp);
        }

        for (String s : array) {
            System.out.println(s);
        }
    }

    public static String compressString(String string) {
        int number = string.length() - 2;
        return(string.charAt(0) + Integer.toString(number) + string.charAt(string.length() - 1));
    }
}
