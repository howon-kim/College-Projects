/*
 * Lab 32
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */

package teamd_lab32;
import java.util.Scanner;
import java.text.NumberFormat;

/**
Write a program that prompts the user to enter the exchange rate from currency in U.S.
dollars to Chinese RMB (or any other country).
Prompt the user to enter 0 to convert from U.S. dollars to Chinese RMB and 1 to convert from Chinese RMB to U.S.
dollars. Prompt the user to enter the amount in U.S. dollars or Chinese RMB to convert it to Chinese RMB or U.S. dollars respectively.
 **/

public class TeamD_lab32 {
    static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        double exchangeRate = 0.0;
        int option = 0;
        double amount = 0.0;
        double result = 0.0;
        
        
        System.out.print("Enter the exchange rate from dollars to RMB (e.g. 6.81): ");
        exchangeRate = sc.nextDouble();
        
        while(exchangeRate <0)
        {
            System.out.print("Enter the exchange rate from dollars to RMB (e.g. 6.81): ");
            exchangeRate = sc.nextDouble();
        }
        
        System.out.print("Enter 0 to convert from U.S. dollars to Chinese RMB and 1 vice versa: ");
        option = sc.nextInt();
        
        NumberFormat number = NumberFormat.getNumberInstance();
        number.setMaximumFractionDigits(2);
        number.setMinimumFractionDigits(2);
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        
        if(option == 0)
        {
            System.out.print("Enter the dollar amount: ");
            amount = sc.nextDouble();
            result = amount * exchangeRate;
            
            System.out.printf("%s is %s yuan%n", currency.format(amount), number.format(result));
        }
        else if(option == 1)
        {
            System.out.print("Enter the RMB amount: ");
            amount = sc.nextDouble();
            result = amount / exchangeRate;
            
            System.out.printf("%s yuan is %s%n", number.format(amount),currency.format(result));
        }
        else
            System.out.println("Incorrect input");
    }
    
}
