import java.util.Arrays;

public class MergeSort {


    public static void main(String[] args) {
//        int[] sampleArray = {15, 28, 50, 22, 14, 5, 3, 32, 10, 30, 43};
        int[] sampleArray = {25, 28, 30, 22, 24, 29, 21, 27, 23, 20, 26};
        System.out.println("Unsorted Array: " + Arrays.toString(sampleArray));
        mergeSort(sampleArray);
        System.out.println("Sorted Array: " + Arrays.toString(sampleArray));
    }

    private static void mergeSort(int[] anArray) {
        int head = 0;
        int tail = anArray.length - 1;
        int[] tmpArray = new int[anArray.length];
        mergeSortAux(anArray, head, tail, tmpArray);
    }

    private static void mergeSortAux(int[] anArray, int head, int tail, int[] tmpArray) {
        if (head < tail) {
            int mid = (head + tail) / 2;

            mergeSortAux(anArray, head, mid, tmpArray);
            mergeSortAux(anArray,mid + 1, tail, tmpArray);

            mergeArrays(anArray,head,mid,tail,tmpArray);
        }
    }

    private static void mergeArrays(int[] anArray, int head, int mid, int tail, int[] tmpArray) {
        int leftPointer = head;
        int rightPointer = mid + 1;
        for (int i = head; i <= tail; i++) {
            if (leftPointer > mid) {
                tmpArray[i] = anArray[rightPointer];
                rightPointer++;
            } else if (rightPointer > tail) {
                tmpArray[i] = anArray[leftPointer];
                leftPointer++;
            } else if (anArray[leftPointer] < anArray[rightPointer]) {
                tmpArray[i] = anArray[leftPointer];
                leftPointer++;
            } else {
                tmpArray[i] = anArray[rightPointer];
                rightPointer++;
            }
        }

        for (int i = head; i <= tail; i++) {
            anArray[i] = tmpArray[i];
        }
    }
}
