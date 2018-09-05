/*
 * Lab 53
 * Team D
 * @author Howon Kim
 */

import java.text.NumberFormat;
public class Order {
    protected String customerName;
    protected int customerNumber;
    protected int quantity;
    protected double unitPrice;
    protected double totalPrice;
    
    NumberFormat currency = NumberFormat.getCurrencyInstance();
    
    Order()
    {
        customerName = "";
        customerNumber = 0;
        quantity = 0;
        unitPrice = 0;
        totalPrice = 0.0;
    }
    protected void computeTotalPrice()
    {
        totalPrice = quantity * unitPrice;
    }
    public void displayFields()
    {
        // Display the field values //
        System.out.println("\n---------- Order Detail ----------");
        System.out.printf("Customer Name   : %s\n",customerName);
        System.out.printf("Customer Number : %d\n",customerNumber);
        System.out.printf("Quantity        : %d\n",quantity);
        System.out.printf("Unit Price      : %s\n",currency.format(unitPrice));
        System.out.printf("Total Price     : %s\n",currency.format(totalPrice));
        System.out.println("----------------------------------\n");

    }
    public void setCustomerName(String name)
    {
        customerName = name;
    }
    public String getCustomerName()
    {
        return customerName;
    }
    public void setCustomerNumber(int number)
    {
        customerNumber = number;
    }
    public int getCustomerNumber()
    {
        return customerNumber;
    }
    public void setQuantity(int quantity)
    {
        this.quantity = quantity;
    }
    public int getQuantity()
    {
        return quantity;
    }
    public void setUnitPrice(double price)
    {
        unitPrice = price;
    }
    public double getUnitPrice()
    {
        return unitPrice;
    }
}
