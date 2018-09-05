/*
 * Assignment 3
 * Payroll part 3
 * Howon Kim
 */
package payroll;
import java.util.Scanner;

/**
Modify the Payroll Program so that it uses a class to store and retrieve the employee's name, the hourly rate, and the number of hours worked. 
Use a constructor to initialize the employee information, and a method within that class to calculate the weekly pay. 
Once stop is entered as the employee name, the application should terminate. 
Make sure the program maintains all the functionality required in previous assignments and your source code is readable and well documented. 
Use feedback you have received from the instructor to make any needed modifications.

You need to have 2 classes: employee and payroll. 
The employee class contains the employee info (name, hourly rate, hours worked), and the getName, setName, getHourlyRate, setHourlyRate, 
getHoursWorked, setHoursWorked, and calculatePay methods. This is a class by itself. 
Then you create the payroll class to use the employee class by initializing it. 
The employee class is saved in the employee.java. The payroll class is saved in the payroll.java. You must compile the employee.java first. 
Make sure that there's no error. Then compile the payroll.java.
**/
public class Payroll {
    
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
       
        employee employee = new employee();


        System.out.println("\n\nWelcome to the Payroll Program!\n");
        
        do
        {
            System.out.print("Please enter the employee name <enter 'stop' to exit the program>: ");
            employee.setName(sc.nextLine()); // Enter the name to the employee object


            if(!employee.getName().equalsIgnoreCase("stop"))
            {
               
                System.out.printf("Please enter the number of hours %s worked: ",employee.getName());
                employee.setHoursWorked(sc.nextDouble()); // Enter the hoursworked to the employee object
                
                while(employee.getHoursWorked()<0)
                {
                    System.out.print("You entered an invalid amount of hours worked. Please enter positive numbers only: ");
                    employee.setHoursWorked(sc.nextDouble());

                }

                
                System.out.printf("Please enter %s's hourly rate: ",employee.getName());
                employee.setHourlyRate(sc.nextDouble()); // Enter the hourly rate to the employee object

                while(employee.getHourlyRate() < 0.0)
                {
                    System.out.print("You entered an invalid hourly rate. Please enter positive numbers only: ");
                    employee.setHourlyRate(sc.nextDouble());
                }
                
                System.out.printf("%nEmployee Name: %s%n", employee.getName());
                System.out.printf("Weekly pay amount : $%.2f%n%n",employee.calculatePay()); 
                sc.nextLine();
            }
            
        }while(!employee.getName().equalsIgnoreCase("stop"));
    }
}