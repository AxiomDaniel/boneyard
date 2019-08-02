package com.axiomdaniel;

public class Vehicle {
    private String name;
    private String size;
    private int currentSpeed;
    private int currentDirection;

    public Vehicle(String name, String size) {
        this.name = name;
        this.size = size;
        this.currentSpeed = 0;
        this.currentDirection = 0;
    }

    public void steer(String direction) {
        System.out.println("Steering at: " + direction + " degrees.");
    }

    public void increaseSpeed(int speed) {
        this.currentSpeed += speed;
    }

    public void decreaseSpeed(int speed) {
        this.currentSpeed -= speed;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public int getCurrentSpeed() {
        return currentSpeed;
    }

    public void setCurrentSpeed(int currentSpeed) {
        this.currentSpeed = currentSpeed;
    }

    public int getCurrentDirection() {
        return currentDirection;
    }

    public void setCurrentDirection(int currentDirection) {
        this.currentDirection = currentDirection;
    }
}
