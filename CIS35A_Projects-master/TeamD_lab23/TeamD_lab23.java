/*
 * Lab 22
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */

package teamd_lab23;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.text.NumberFormat;

/*
 * Write a program that prompts the user to enter the distance to drive, 
 * the fuel efficiency of the car in miles per gallon, and the price per gallon, and displays the cost of the trip.
 */
public class TeamD_lab23 {
    public static void main(String[] args) {
        double distance = 0.0;
        double fuelEfficiency = 0.0;
        double price = 0.0;
        double cost = 0.0;
        boolean success = true;
        
        Scanner sc = new Scanner(System.in);
        
        while(success)  
        {
            try
            {
                System.out.print("Enter the distance to drive : ");
                distance = sc.nextDouble();
                System.out.print("Enter the fuel efficiency of the car in miles per gallon : ");
                fuelEfficiency = sc.nextDouble();
                System.out.print("Enter the price per gallon : ");
                price = sc.nextDouble();
                success = false;

            }
            catch(InputMismatchException e)
            {
                sc.next(); // discard the incorrectly entered number
                System.out.println("Error! Invalid number. Try again.\n");
                continue;
            }
        }
        
        cost = (distance/fuelEfficiency) * price;
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        String stringCost = currency.format(cost);
        
        System.out.printf("Cost of the trip : %s%n", stringCost);

    }
   
}
