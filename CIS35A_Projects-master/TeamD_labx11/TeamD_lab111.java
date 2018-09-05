/*
 Create a program that allows a user to input customer records 
 (ID number, first name, last name, and balance owed) 
 and save each record to a file. 
 Use a delimiter to seperate the records. 
 When you execute the program, be sure to enter multiple records that have the same last name.
 */
package teamd_lab111;

import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Lab 11.1
 * @author HWKIM
 */

public class TeamD_lab111 {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("CustomerList.txt");
        String ID = "", firstName, lastName;
        double balance;
        
        if(file.exists()){
            System.out.println("File already exists");
            System.exit(0);
        }   
        
        try (PrintWriter output = new PrintWriter(file);)
        {
            while(!ID.equalsIgnoreCase("ZZZ")){
                System.out.print("Enter ID number or ZZZ to quit >> ");
                ID = sc.next();

                if(!ID.equalsIgnoreCase("ZZZ")){
                  System.out.print("Enter first name >> ");
                  firstName = sc.next();
                  System.out.print("Enter last name >> ");
                  lastName = sc.next();
                  System.out.print("Enter balance >> ");
                  balance = sc.nextDouble();
                  
                  output.print(ID);
                  output.print(",");
                  output.print(firstName);
                  output.print(",");
                  output.print(lastName);
                  output.print(",");
                  output.println(balance);
                  
                }
            }
            output.close();
        }
    }
}
