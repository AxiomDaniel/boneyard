package com.axiomdaniel;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int newScore = calculateScore("Tim" , 500);
        calculateScore(75);
        calculateScore();

        System.out.println(CalcFeetAndInchesToCentimeters.calcFeetAndInchesToCentimeters(100));
        System.out.println(CalcFeetAndInchesToCentimeters.calcFeetAndInchesToCentimeters(7,-5));
    }

    public static int calculateScore(String playerName, int score) {
        System.out.println("Player " + playerName + " scored " + score + " points");
        return score * 1000;
    }

    public static int calculateScore(int score) {
        System.out.println("Unnamed player scored " + score + " points");
        return score * 1000;
    }

    public static int calculateScore() {
        System.out.println("No player name, no player score.");
        return 0;
    }
}

// Method overloading just means using the same method keyword, but having different parameters
// This is useful in java as sometimes we need to call the same function, but have different parameters.\
// Note: Changing the return data type doesn't overload a method.
