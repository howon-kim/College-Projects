/*
 * Lab 24
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */

package teamd_lab24;
import java.util.Scanner;
import java.lang.Math;

/**
You want to create a program to get the first name, last name, address, city, state and zip code, 
and display the information with the city name followed by a comma, a space, the state name, one space, and the ZIP code. 
The program also generates California lotto numbers for the Mega Millions.

To generate the numbers, pick five lucky numbers from 1 to 75 and one MEGA number from 1 to 15.

For example

John Doe
123 Stevens Creek Dr
San Jose, CA 95129

The lotto numbers for Mega Millions are:
7 16 28 53 60
Mega: 2
**/

public class TeamD_lab24 {

    public static void main(String[] args) {
        String firstName;
        String lastName;
        String address;
        String city;
        String state;
        String zipCode;
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the First Name : ");
        firstName = sc.nextLine();
        System.out.print("Enter the Last Name : ");
        lastName = sc.nextLine();
        System.out.print("Enter the Address : ");
        address = sc.nextLine();
        System.out.print("Enter the City : ");
        city = sc.nextLine();
        System.out.print("Enter the State : ");
        state = sc.next();
        System.out.print("Enter the Zip Code : ");
        zipCode = sc.next();
        
        int luckyNum1 = (int)((Math.random()*100)%75+1);
        int luckyNum2 = (int)((Math.random()*100)%75+1);
        int luckyNum3 = (int)((Math.random()*100)%75+1);
        int luckyNum4 = (int)((Math.random()*100)%75+1);
        int luckyNum5 = (int)((Math.random()*100)%75+1);
        int megaNum = (int)((Math.random()*100)%15+1);
               
        System.out.println("\n");
        System.out.printf("%s %s %n",firstName, lastName);
        System.out.printf("%s%n",address);
        System.out.printf("%s, %s %s%n",city,state,zipCode);
        System.out.println();
        System.out.println("The lotto numbers for Mega Millions are:");
        System.out.printf("%d %d %d %d %d %n",luckyNum1,luckyNum2,luckyNum3,luckyNum4,luckyNum5);
        System.out.printf("Mega: %d%n",megaNum);

        
    }
    
}
