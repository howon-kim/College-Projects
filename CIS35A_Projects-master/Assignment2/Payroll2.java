/**
 * Assignment 2
 * Howon Kim
 */
package payroll2;
import java.util.Scanner;
import java.text.NumberFormat;
import java.util.InputMismatchException;

/**
 Modify the Payroll Program application so it continues to request employee information 
 until the user enters stop as the employee name. 
 In addition, program the application to check that the hourly rate and number of hours worked are positive numbers. 
 If either the hourly rate or the number of hours worked is not a positive value, 
 the application should prompt the user to enter a positive amount.
 */

public class Payroll2 {    
    public static void main(String[] args) {
        String name = "";
        int workTime = 0;
        double hourlyRate = 0.0;
        double payAmount = 0.0;
        boolean check = true;
        
        System.out.println("\n\nWelcome to the Payroll Program!\n");
        
        do
        {
            Scanner sc = new Scanner(System.in);
            System.out.print("Please enter the employee name <enter 'stop' to exit the program>: ");
            name = sc.nextLine();

            if(!name.equalsIgnoreCase("stop"))
            {
                while(check)
                {
                    try
                    {
                        System.out.printf("Please enter the number of hours %s worked: ",name);
                        workTime = sc.nextInt();
                        while(workTime<0)
                        {
                            System.out.println("You entered an invalid amount of hours worked. Please enter positive numbers only: ");
                            workTime = sc.nextInt();
                        }
                        check = false;
                    }
                    catch(InputMismatchException e)
                    {
                        sc.next(); // discard the incorrectly entered number
                        System.out.println("Error! Invalid number. Try again.\n");
                        continue;
                    }
                }

                check = true;

                while(check)
                {
                    try
                    {
                        System.out.printf("Please enter %s's hourly rate: ",name);
                        hourlyRate = sc.nextDouble();
                        while(hourlyRate < 0.0)
                        {
                            System.out.println("You entered an invalid hourly rate. Please enter positive numbers only: ");
                            hourlyRate = sc.nextDouble();
                        }
                        check = false;
                    }
                    catch(InputMismatchException e)
                    {
                        sc.next(); // discard the incorrectly entered number
                        System.out.println("Error! Invalid number. Try again.\n");
                        continue;
                    }
                }

                check = true;
                payAmount = workTime * hourlyRate;
                NumberFormat currency = NumberFormat.getCurrencyInstance();
                String stringPayAmount = currency.format(payAmount);

                System.out.printf("%nEmployee Name: %s%n", name);
                System.out.printf("Weekly pay amount : %s%n%n",stringPayAmount); 
            }
            
        }while(!name.equalsIgnoreCase("stop"));
       
    }
}