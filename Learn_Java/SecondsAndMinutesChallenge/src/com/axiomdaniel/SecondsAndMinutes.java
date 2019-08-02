package com.axiomdaniel;

public class SecondsAndMinutes {
    public static String getDurationString(int minutes, int seconds) {
        if (minutes < 0 || seconds < 0 || seconds > 59) {
            return "Invalid value";
        }
        int hours = minutes / 60;
        int mins = minutes % 60;
        return(hours + "h " +
                mins + "m " +
                seconds + "s");
    }

    public static String getDurationString(int seconds) {
        if (seconds < 0) {
            return "Invalid value";
        }
        int mins = seconds / 60;
        return getDurationString(mins, seconds % 60);
    }
}
