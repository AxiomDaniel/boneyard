package com.axiomdaniel;

public class FlourPacker {
    // write your code here
    public static boolean canPack(int bigCount, int smallCount, int goal) {
        if (bigCount < 0 || smallCount < 0 || goal < 0) {
            return false;
        }

        while (bigCount > 0 && goal >= 5) {
            bigCount -= 1;
            goal -= 5;
        }

        while (smallCount > 0 && goal > 0) {
            smallCount -= 1;
            goal -= 1;
        }

        return (goal == 0);
    }
}