/*
 * Lab 22
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */
package teamd_lab22;

import java.util.Scanner;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.NumberFormat;

/*
Suppose you save $100 each month into a savings account with the annual interest rate 5%. 
Thus, the monthly interst rate is 0.05/12= 0.00417. After the first month, the value in the account becomes:
100 * (1 + 0.00417) = 100.417

After the second month, the value in the account becomes
(100 + 100.417) * (1 + 0.00417) = 201.252

After the third month, the value in the account becomes
(100 + 201.252) * (1 + 0.00417) = 302.507

and so on.

Write a program that prompts the suer to enter a monthly saving amount and displays the account value after the sixth month.
Do not use loops.
*/

public class TeamD_lab22 {

    public static void main(String[] args) {
        
        double account = 0.0;
        double interestRate = 0.05/12;
        double savingAmount = 0.0;
        
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter monthly saving amount : $");
        savingAmount = sc.nextDouble();
        
        
        account = (savingAmount + account) * (1+interestRate); // After 1 month
        account = (savingAmount + account) * (1+interestRate); // After 2 month
        account = (savingAmount + account) * (1+interestRate); // After 3 month
        account = (savingAmount + account) * (1+interestRate); // After 4 month
        account = (savingAmount + account) * (1+interestRate); // After 5 month
        account = (savingAmount + account) * (1+interestRate); // After 6 month

        BigDecimal decimalAccount = new BigDecimal(account);
        decimalAccount = decimalAccount.setScale(3, RoundingMode.HALF_UP);
        
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        
        String stringAccount = currency.format(decimalAccount);
        
        System.out.printf("Account Value : %s %n",stringAccount);
    }
    
}
