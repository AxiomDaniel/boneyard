import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        int max = Integer.MIN_VALUE;
        for (int i = 1; i < arr.length - 1; i++) {
            for (int j = 1; j < arr.length - 1; j++) {
                int sum = calcHourglassPosition(arr, i, j);
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }

    static int calcHourglassPosition(int[][] arr, int row, int col) {
        int sum = 0;
        sum += arr[row][col];       // Center
        sum += arr[row-1][col-1];   // Top left
        sum += arr[row-1][col];     // Top
        sum += arr[row-1][col+1];   // Top right
        sum += arr[row+1][col-1];   // Bottom left
        sum += arr[row+1][col];     // Bottom
        sum += arr[row+1][col+1];   // Bottm right
        return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
