package com.axiomdaniel;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Please enter the count: \r");
        int count = scanner.nextInt();
        scanner.nextLine();
        int[] theArray = readIntegers(count);
        System.out.println("Smallest number is: " + findMin(theArray));

    }

    private static int[] readIntegers(int count) {
        int[] newArray = new int[count];
        for (int i = 0; i < count; i++) {
            System.out.println("Please enter number: " + (i + 1));
            newArray[i] = scanner.nextInt();
            scanner.nextLine();
        }
        return newArray;
    }

    private static int findMin(int[] array) {
        int min = 0;
        for (int i = 1; i < array.length; i++) {
            if (array[min] > array[i]) {
                min = i;
            }
        }
        return array[min];
    }
}
