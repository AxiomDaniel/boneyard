import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Solution {

    // Complete the repeatedString function below.
    static long repeatedString(String s, long n) {
        long countA = 0;
        // Count the number of 'a' in the full string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                countA++;
            }
        }

        long remainder = n % s.length();
        long remainderCount = 0;
        for (int i = 0; i < remainder; i++) {
            if (s.charAt(i) == 'a') {
                remainderCount++;
            }
        }

        long multiple = n / s.length();
        return  multiple * countA + remainderCount;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        long n = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = repeatedString(s, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}