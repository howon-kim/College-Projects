/*
 Write a program that uses the Calendar class. 
 Get the current date and time. Display it. 
 ALso display the day of year and hour of day. 
 Ask the user to enter the number of days and hours to add. 
 Set the day and hour. Display the new date and time.
 */
package teamd_lab91;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 * Lab 9.1
 * @author HWKIM
 */

public class TeamD_lab91 {

    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        GregorianCalendar cal = new GregorianCalendar();
        
        System.out.println(cal.getTime());
        System.out.printf("day of year = %d\n",cal.get(Calendar.DAY_OF_YEAR));
        System.out.printf("hour of day = %d\n",cal.get(Calendar.HOUR_OF_DAY));
        
        System.out.println("Enter number of days to add:");
        cal.add(Calendar.DATE, sc.nextInt());
        
        System.out.println("Enter number of hours to add:");
        cal.add(Calendar.HOUR, sc.nextInt());
        
        System.out.println(cal.getTime());
                
    }
    
}
