/*
 Assignment 1
 Howon Kim
 */
package payroll;
import java.util.Scanner;
import java.text.NumberFormat;
import java.util.InputMismatchException;

/**
Create a non-GUI-based Java application that calculates weekly pay for an employee. 
The application should display text that requests the user input the name of the employee, 
the hourly rate, and the number of hours worked for that week. 
The application should then print out the name of the employee and the weekly pay amount. 
In the printout, display the dollar symbol ($) to the left of the weekly pay amount and 
format the weekly pay amount to display currency.
**/

public class Payroll {

    public static void main(String[] args) {
        System.out.println("\n\nWelcome to the Payroll Program!");
        System.out.println();
        
        Scanner sc = new Scanner(System.in);
        
        String name = "";
        int workTime = 0;
        double hourlyRate = 0.0;
        double payAmount = 0.0;
        boolean check = true;

        System.out.print("Please enter the employee name: ");
        name = sc.nextLine();
        
        while(check)
        {
            try
            {
                System.out.printf("Please enter the number of hours %s Worked: ",name);
                workTime = sc.nextInt();
                System.out.printf("Please enter %s's hourly rate: ",name);
                hourlyRate = sc.nextDouble();
                check = false;
            }
            catch(InputMismatchException e)
            {
                sc.next(); // discard the incorrectly entered number
                System.out.println("Error! Invalid number. Try again.\n");
                continue;
            }
        }
        
        payAmount = workTime * hourlyRate;
        System.out.println("\n");
        
        System.out.printf("Employee Name: %s%n",name);
        
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        
        String stringPayAmount = currency.format(payAmount);
        
        System.out.printf("Weekly pay amount : %s%n%n",stringPayAmount);
        

        
        
    }
    
}
