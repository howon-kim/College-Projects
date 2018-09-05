/*
 Write a program that prompts the user to read two integers and display their sum. 
 Your program should prompt the user to read the number again if the input is incorrect.
 */
package teamd_lab92;
import static com.sun.corba.se.impl.util.Utility.printStackTrace;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Team 9.2
 * @author HWKIM
 */

public class TeamD_lab92 {

    public static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        int num1 = 0;
        int num2 = 0;
        boolean check = false;
        
        while(!check) {
            try {
                System.out.print("Enter two integers: ");

                num1 = sc.nextInt();
                num2 = sc.nextInt();
                                
                check = true;
            } 
            catch (InputMismatchException ex) {
                sc.nextLine();
                ex.printStackTrace();  
            }
        }
        
        System.out.printf("Sum is %d\n",num1+num2);
    }
}
