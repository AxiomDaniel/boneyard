public class BinarySearch {

    public static void main(String[] args) {
        int[] sampleList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert binarySearch(sampleList,0) == 0;
        assert binarySearch(sampleList,1) == 1;
        assert binarySearch(sampleList,2) == 2;
        assert binarySearch(sampleList,3) == 3;
        assert binarySearch(sampleList,4) == 4;
        assert binarySearch(sampleList,5) == 5;
        assert binarySearch(sampleList,6) == 6;
        assert binarySearch(sampleList,7) == 7;
        assert binarySearch(sampleList,8) == 8;
        assert binarySearch(sampleList,9) == 9;
        assert binarySearch(sampleList,-1) == -1;
        assert binarySearch(sampleList,10) == -1;

        int[] sampleList1 = {1, 3, 5, 7, 9};
        int[] sampleList2 = {0, 2, 4, 6, 8};
        assert binarySearch(sampleList1,2) == -1;
        assert binarySearch(sampleList1,4) == -1;
        assert binarySearch(sampleList1,6) == -1;
        assert binarySearch(sampleList1,8) == -1;

        assert binarySearch(sampleList2,1) == -1;
        assert binarySearch(sampleList2,3) == -1;
        assert binarySearch(sampleList2,5) == -1;
        assert binarySearch(sampleList2,7) == -1;

    }

    private static int binarySearch(int[] anArray, int element) {
        int head = 0;
        int tail = anArray.length - 1;
        int ptr = (head + tail) / 2;
        while (head <= tail) {
            if (anArray[ptr] == element) {
                return ptr;
            } else if (anArray[ptr] < element) {
                head = ptr + 1;
            } else {
                tail = ptr - 1;
            }
            ptr = (head + tail) / 2;
        }
        return -1;
    }
}
