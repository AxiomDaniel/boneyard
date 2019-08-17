import java.util.Arrays;

public class InsertionSort {

    public static void main(String[] args) {
        int[] sampleArray = {15, 28, 50, 22, 14, 5, 3, 32, 10, 30, 43};
        System.out.println("Unsorted Array: " + Arrays.toString(sampleArray));

        insertionSort(sampleArray);

        System.out.println("Sorted Array: " + Arrays.toString(sampleArray));

    }

    private static void insertionSort(int[] anArray) {
        for (int i = 1; i < anArray.length; i++) {
            int tmp = anArray[i];
            for (int k = i - 1; k > -1; k--) {
                if (anArray[k] > tmp) {
                    anArray[k + 1] =  anArray[k];
                    anArray[k] = tmp;
                } else {
                    break;
                }
            }
        }
    }
}
