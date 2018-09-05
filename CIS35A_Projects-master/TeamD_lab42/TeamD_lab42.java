/*
 * Lab 42
 * Team D
 * @author Howon Kim
 * @author Young Kim
 */

package teamd_lab42;
import java.util.Scanner;

/**
Write a method with following header to format the integer with the specified width:

public static String format(int number, int width)

The method returns a string for the number with one or more prefix 0s. 

The size of the string is the width. 
For example, format(25, 4) returns 0025 and format(25,5) returns 00025. 

If the number is longer than the width, the method returns the string representation for the number. 
For example, format(25, 1) returns 25.

Write a test program that prompts the user to enter a number and its width and displays a string returned by invoking format(number, width).
**/

public class TeamD_lab42 {
    static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        
        int number = 0;
        int width = 0;
        
        System.out.print("Enter the number : ");
        number = sc.nextInt();
        while(number < 0)
        {
            System.out.print("Enter the number : ");
            number = sc.nextInt(); 
        }
        
        System.out.print("Enter the width : ");
        width = sc.nextInt();
        while(width < 0)
        {
            System.out.print("Enter the width : ");
            width = sc.nextInt();
        }
        
        System.out.printf("%s\n",format(number,width));

    }
    
    public static String format(int number, int width)
    {        
        Integer temp  = new Integer(number);
        String tempNumber = Integer.toString(temp);
        String result = "";
        
        int length = tempNumber.length();
        int numZero = width - length;
        
        if(numZero > 0)
        {
            for(int i = 1; i<= numZero; i++)
            {
                result  += 0;
            }
        }
        result += tempNumber;
        
        return result;
    }


}
