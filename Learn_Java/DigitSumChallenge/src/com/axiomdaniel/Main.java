package com.axiomdaniel;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(sumDigits(125));
    }

    public static int sumDigits(int number) {
        int sum = 0;

        if (number < 10) {
            return -1;
        }
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
}
