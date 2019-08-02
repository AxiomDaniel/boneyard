package com.axiomdaniel;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    int min = Integer.MAX_VALUE;    //2147483647
	    int max = Integer.MIN_VALUE;    //-2147483648
	    boolean first = true;
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Please enter number: ");
            if (scanner.hasNextInt()) {
                int number = scanner.nextInt();

//                Write this snippet if you're forced to declare a variable first. Which is unlikely. Use -infinity and infinity
//                if (first) {
//                    first = false;
//                    min = number;
//                    max = number;
//                }

                if (min > number) {
                    min = number;
                }

                if (max < number) {
                    max = number;
                }
            } else {
                break;
            }
            scanner.nextLine();
        }

        System.out.println("Min number: " + min + " Max number: " + max);
        scanner.close();
    }
}
