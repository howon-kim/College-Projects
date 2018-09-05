/**
Create a class named Order that performs order processing of a single item. 
The class has five fields: customer name, customer number, quantity ordered, unit, price, and total price. 
Include set and get methods for each field except the total price field. 
The set methods prompt the user for values for each field. 
This class also needs a method to compute the total price (quantity times unit price) and a method to display the field values. 
Save the file as Order.java.

Create a subclass named ShippedOrder that overrides computePrice() by adding a shipping and handling charge of $400. 
Save the file as ShippedOrder.java.

Write an application named UseOrder that instantiates an object of each of these classes. 
Prompt the user for data for the Order object, and display the results; 
then prompt the user for data for the SHippedOrder object, and display the results. Save the file as UseOrder.java.
**/

/*
 * Lab 53
 * Team D
 * @author Howon Kim
 */

import java.util.Scanner;

public class UseOrder {
    
    public static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
   
        Order order = new Order();
        ShippedOrder shipOrder = new ShippedOrder(); // Same with Order shipOrder = new ShippedOrder();

        // Input data for order object
        System.out.println("\n-----Data for the Order object-----");
        System.out.print("Enter the Customer Name    : ");
        order.setCustomerName(sc.nextLine());
        System.out.print("Enter the Customer Number  : ");
        order.setCustomerNumber(sc.nextInt());
        System.out.print("Enter the Quantity Ordered : ");
        order.setQuantity(sc.nextInt());
        System.out.print("Enter the Unit Price       : ");
        order.setUnitPrice(sc.nextDouble());
        
        // Display and calculate the data for order object
        System.out.println();
        order.computeTotalPrice();
        order.displayFields();
        
        
        // Input data for ShippedOrder object
        sc.nextLine();
        System.out.println("\n-----Data for the ShippedOrder object-----");
        System.out.print("Enter the Customer Name    : ");
        shipOrder.setCustomerName(sc.nextLine());
        System.out.print("Enter the Customer Number  : ");
        shipOrder.setCustomerNumber(sc.nextInt());
        System.out.print("Enter the Quantity Ordered : ");
        shipOrder.setQuantity(sc.nextInt());
        System.out.print("Enter the Unit Price       : ");
        shipOrder.setUnitPrice(sc.nextDouble());
        
        // Display and calculate the data for shippedorder object
        System.out.println();
        shipOrder.computeTotalPrice();
        shipOrder.displayFields();
        
        }
}
