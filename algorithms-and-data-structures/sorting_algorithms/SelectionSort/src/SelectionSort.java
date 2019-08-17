import java.util.Arrays;

public class SelectionSort {

    public static void main(String[] args) {
        int[] sampleArray = {15, 28, 50, 22, 14, 5, 3, 32, 10, 30, 43};
        System.out.println("Unsorted Array: " + Arrays.toString(sampleArray));

        selectionSort(sampleArray);

        System.out.println("Sorted Array: " + Arrays.toString(sampleArray));

    }

    private static void selectionSort(int[] anArray) {
        for (int i = 0; i < anArray.length; i++) {
            int minIndex = findMin(anArray,i);
            int tmp = anArray[i];
            anArray[i] = anArray[minIndex];
            anArray[minIndex] = tmp;
        }

    }

    private static int findMin(int[] anArray, int startingIndex) {
        int min = startingIndex;
        for (int i = startingIndex + 1; i < anArray.length; i++) {
            if (anArray[min] > anArray[i]) {
                min = i;
            }
        }
        return min;
    }
}
