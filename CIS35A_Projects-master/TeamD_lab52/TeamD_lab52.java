/*
 * Lab 52
 * Team D
 * @author Howon Kim
 */

package teamd_lab52;
import java.util.Scanner;
import java.lang.String;

/**
Write a method to validate a social security number. 
This method should accept a Scanner object and a string that will be displayed to the user as a prompt. 
After it accepts the social security number, this method should check that entry contains 11 characters. 
If it does, the method should validate the entry by checking that the first three characters are numeric digits, 
the fourth character is a hyphen, the fifth and sixth characters are numeric digits, the seventh character is a hyphen, 
and the eight through eleventh characters are numeric digits. 
To check for a numeric digit, you can use a private method that tests if a character is equal to any of the numbers from 0 through 9. 
If the user's entry doesn't conform to this format, the method should display an error message and ask the user to enter the number again.

Write a test program that calls this method.
**/

public class TeamD_lab52 {

    public static void main(String[] args) {
        String input = new String();
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the Social Security Number (xxx-xx-xxxx): ");
        input = sc.next();

        validate(sc, input);

    }
    
    private static void validate(Scanner sc, String input){        
        while(input.length() != 11 || !input.substring(0,3).matches("[\\d]{3}") || !input.substring(3,4).matches("-") || !input.substring(4,6).matches("[\\d]{2}") || !input.substring(6,7).matches("-") || !input.substring(7,11).matches("[\\d]{4}"))
        {
            System.out.print("Incorrect Social Security Number! Enter the Social Security Number (xxx-xx-xxxx): ");
            input = sc.next();  
        }
    }
    
}
