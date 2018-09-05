/*
 * Lab 51
 * Team D
 * @author Howon Kim
 */

package teamd_lab51;
import java.util.Scanner;
import java.lang.String;

/**
Write an application that parses full names into first and last name or first, middle, and last name, 
depending on whether the user enters a string consisting of two or three words.

Sample run

Welcome to the name parser.
Enter a name: John Doe

First name: John
Last name: Doe
* 
Another run with middle name.

Welcome to the name parser.
Enter a name: John Albert Doe

First name: John
Middle name: Albert
Last name: Doe
**/

public class TeamD_lab51 {
    static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        
        System.out.println("Welcome to the name parser.");
        System.out.print("Enter a name: ");
        String fullName = new String(sc.nextLine());
        fullName = fullName.trim();
        
        /* Result after parsing */
        String firstName = new String();
        String middleName = new String();
        String lastName = new String();
        
        int index = 0;
        int current = 0;
        
        current = fullName.indexOf(" ", current);
        index = current;
        firstName = fullName.substring(0, current);
            
        while(current != -1)
        {
            current = fullName.indexOf(" ", current +1);
            
            if(current == -1)
                lastName = fullName.substring(index +1, fullName.length());
            else
            {
                middleName += fullName.substring(index +1, current +1);
                index = current;
            }            
        }
        
        /** Array Version
        String[] nameParts = fullName.split(" ");
        int index = nameParts.length - 1;
        
        // Parsing Process 
        for(int i = 0 ; i <= index ; i++)
        {
            if(i == 0)
                firstName = nameParts[i];
            
            
            if(i != 0 && i != index)
                middleName += nameParts[i] + " ";
            
            
            if(i == index)
                lastName = nameParts[i];   
        }
        **/
        
        /* Print the Result */
        System.out.println();
        System.out.printf("First name: %s\n", firstName);
        if(middleName.length() > 0)
        {
            middleName = middleName.trim();
            System.out.printf("Middle name: %s\n", middleName);
        }
        System.out.printf("Last name: %s\n", lastName);
    
    }
}