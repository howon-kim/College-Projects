/*
 * Lab 21
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */

package teamd_lab21;
import java.util.Scanner;
import java.text.NumberFormat;

/*
Here is the problem specification:

Write a program that reads the bill and the gratuity rate, then computes the gratuity and total. 
For Example, if the user enters 10 for the bill and 15% for the gratuity rate, 
the program should display $1.50 ad gratuity and $11.50 as total.
*/

public class TeamD_lab21 {

    public static void main(String[] args) {
        
        String input = "";
        double gratuityRate = 0.0;
        
        double bill = 0.0;
        double total = 0.0;
        double gratuity = 0.0;
       
        Scanner sc = new Scanner(System.in);
        
        System.out.printf("Enter the bill : ");
        bill = sc.nextDouble();
        
        System.out.printf("Enter the gratuity rate : ");
        input = sc.next();
        gratuityRate = Double.parseDouble(input.replaceAll("%", ""));
        
        gratuityRate *= 0.01;       
        gratuity = gratuityRate * bill;
        total = bill + gratuity;
        
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        
        String totalString = currency.format(total);
        String gratuityString = currency.format(gratuity);
        String billString = currency.format(bill);
        
        System.out.println("----- RECEIPT -----");
        System.out.printf("Bill     : %s %n",billString);
        System.out.printf("Gratuity : %s %n",gratuityString);
        System.out.printf("Total    : %s %n", totalString);
    
    }
    
}
