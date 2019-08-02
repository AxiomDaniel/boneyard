package com.axiomdaniel;

public class Main {

    public static void main(String[] args) {
        int value = 3;
        if (value == 1) {
            System.out.println("Value is 1");
        } else if (value == 2) {
            System.out.println("Value is 2");
        } else {
            System.out.println("Value is not 1 or 2");
        }


        //Switch statement

        int switchValue = 5;

        switch(switchValue) {
            case 1:
                System.out.println("Value is 1");
                break;
            case 2:
                System.out.println("Value is 2");
                break;
            case 3: case 4: case 5:
                System.out.println("Value is 3,4 or 5");
                break;
            default:
                System.out.println("Value is not 1 to 5");
                break;
        }

        // Remember to add the parameter to the switch.
        // Remember to add break to each case
        // The final case is default.

        char switchChar = 'A';

        switch(switchChar) {
            case 'A':
                System.out.println("Char is A");
                break;
            case 'B':
                System.out.println("Char is B");
                break;
            case 'C':
                System.out.println("Char is C");
                break;
            default:
                System.out.println("Char is not found.");
                break;

        }
    }
}
