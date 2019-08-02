package com.axiomdaniel;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner scanner = new Scanner(System.in);
        int count = 0;
        int sum = 0;
        while (count < 10) {
            System.out.println("Please enter number #" + (count + 1) + ": ");
            if (scanner.hasNextInt()) {
                sum += scanner.nextInt();
                count += 1;
            } else {
                System.out.println("Invalid value");
            }
            scanner.nextLine();
        }
        System.out.println("Sum of 10 numbers is: " + sum);
        scanner.close();
    }
}
