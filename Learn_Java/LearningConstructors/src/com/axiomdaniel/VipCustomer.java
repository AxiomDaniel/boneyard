package com.axiomdaniel;

public class VipCustomer {

    private String name;
    private String accountNumber;
    private double balance;

    public VipCustomer(String name, String accountNumber, double balance) {
        this.name = name;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public VipCustomer() {
        this("Test Customer", "000000", 9999.99);
    }

    public VipCustomer(String name, double balance) {
        this(name, "00000", balance);
    }

    public String getName() {
        return name;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public String getCustomerDetails() {
        return ("Name: " + this.getName() +
                ", Acct No: " + this.getAccountNumber() +
                ", Balance: " + this.getBalance());
    }
}
