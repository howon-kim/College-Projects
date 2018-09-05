/*
 * Lab 34
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */


package teamd_lab34;
import java.text.NumberFormat;

/**
You have just started a sales job in a department store. 
Your pay consists of a base salary and a commission. The base salary is $5,000. 
The commission rates are as follows:

$0.01 - $5,000 : 8%
$5,000.01 - $10,000 : 10%
$10,000.01 and above : 12%

Note that this is a graduated rate. The rate for the first $5,000 is at 8%, the next $5,000 is at 10%, and the rest is at 12%.
If the sales amount is $25,000, the commission is 5000*0.08+5000*0.10+15000*0.12=2700.

Your goal is to earn $30,000 a year. 
Write a program that finds the minimum sales you have to generate in order to make $30,000.
**/


public class TeamD_lab34 {
    static int BASE_SALARY = 5000;
    static double GRADUATE_RATE_5000 = 0.08;
    static double GRADUATE_RATE_10000 = 0.10;
    static double GRADUATE_RATE_ABOVE = 0.12;
    
    public static void main(String[] args) {
        
        double goal = 30000;
        double commission = 0.0;
        double salesAmount = 0.0;
        
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        
        commission = goal - BASE_SALARY;
        
        if(commission <= 400)
        {
            salesAmount = commission / GRADUATE_RATE_5000;
            
            System.out.printf("Base Sales   : %15s%n", currency.format(BASE_SALARY));
            System.out.printf("Commission   : %15s%n", currency.format(commission));
            System.out.println("-------------------------------");
            System.out.printf("Goal         : %15s%n" , currency.format(goal));
            System.out.printf("Minimum Sales: %15s%n", currency.format(salesAmount));
            System.out.println("-------------------------------");

        }
        else if(commission > 400 && commission <= 900)
        {
            salesAmount = (400 / GRADUATE_RATE_5000) + ((commission - 400) / GRADUATE_RATE_10000);
            
            System.out.printf("Base Sales   : %15s%n", currency.format(BASE_SALARY));
            System.out.printf("Commission   : %15s%n", currency.format(commission));
            System.out.println("-------------------------------");
            System.out.printf("Goal         : %15s%n" , currency.format(goal));
            System.out.printf("Minimum Sales: %15s%n", currency.format(salesAmount));
            System.out.println("-------------------------------");
        }
        else
        {
            salesAmount = (400 / GRADUATE_RATE_5000) + (500 / GRADUATE_RATE_10000) + ((commission - 900) / GRADUATE_RATE_ABOVE);
            
            System.out.printf("Base Sales   : %15s%n", currency.format(BASE_SALARY));
            System.out.printf("Commission   : %15s%n", currency.format(commission));
            System.out.println("-------------------------------");
            System.out.printf("Goal         : %15s%n" , currency.format(goal));
            System.out.printf("Minimum Sales: %15s%n", currency.format(salesAmount));
            System.out.println("-------------------------------");
        }
    }    
}
