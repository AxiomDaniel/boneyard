import java.util.Scanner;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(solver(scanner.nextLine()));
    }

    private static String solver(String aString) {
        if (isAllCaps(aString)) {
            return aString.toLowerCase();
        } else if (isFirstLowerCase(aString)) {
            return convertCaps(aString);
        }
        return aString;
    }

    private static boolean isAllCaps(String aString) {
        for (int i = 0; i < aString.length(); i++) {
            if (Character.isLowerCase(aString.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    private static String convertCaps(String aString) {
        StringBuilder str = new StringBuilder();
        str.append(Character.toUpperCase(aString.charAt(0)));
        str.append(aString.substring(1).toLowerCase());
        return str.toString();
    }

    private static boolean isFirstLowerCase(String aString) {
        if (Character.isUpperCase(aString.charAt(0))) {
            return false;
        } else {
            return isAllCaps(aString.substring(1));
        }
    }
}
