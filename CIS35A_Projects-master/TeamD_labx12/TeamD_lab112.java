/*
Write an application that allows you to enter any last name and displays 
all the data for customers with the given last name (stored in the file created in lab 11.1).
Display an appropriate message if the name cannot be found in the input file.
 */

package teamd_lab112;

import java.io.*;
import java.nio.file.*;
import java.util.Scanner;

/**
 * Lab 11.2
 * @author HWKIM
 */

public class TeamD_lab112 {

    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Path file = Paths.get("CustomerList.txt");
        String[] array = new String[3];
        String s = "";
        String delimiter = ",";
        
        String id;
        String firstName;
        String lastName;
        double balance;
        
        String search;
        Boolean find = false;

        try
        {
            InputStream input = new BufferedInputStream(Files.newInputStream(file));
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            s = reader.readLine();

                    
            System.out.print("\nEnter last name to search for >> ");
            search = sc.next();
            
            while(s != null)
            {
                array = s.split(delimiter);
                id = array[0];
                firstName = array[1];
                lastName = array[2];
                balance = Double.parseDouble(array[3]);
                
                if(lastName.contentEquals(search))
                {
                    System.out.print(id + " ");
                    System.out.print(firstName + " ");
                    System.out.print(lastName + " ");
                    System.out.print(balance);
                    System.out.println();
                    find = true;
                }

                s = reader.readLine();
            }
            reader.close();
           
            if(find == false)
            {
              System.out.println(search + " is not on the list"); 
            }
        }
        catch(Exception e)
        {
            System.out.println("Message: " + e);
        }
    }
}