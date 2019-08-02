package com.axiomdaniel;

public class Main {

    public static void main(String[] args) {
	// write your code here
        VipCustomer test = new VipCustomer();
        System.out.println(test.getCustomerDetails());

        VipCustomer test1 = new VipCustomer("Daniel", 100.01);
        System.out.println(test1.getCustomerDetails());

        VipCustomer test2 = new VipCustomer("Xiong Xiong", "1100 1550", 2600.57);
        System.out.println(test2.getCustomerDetails());
    }
}
