/*
 * Lab 31
 * Team D
 * @author Howon Kim
 * @author Young Kim
 * @author Andy Huynh
 * @author Zhang
 */


package teamd_lab31;
import java.util.Scanner;

/**
Write a program that prompts the user to enter an integer for today's day of the week 
(Sunday is 0, Monday is 1, etc.)
Also prompts the user to enter the number of days after today for a future day and display the future day of the week

Enter today's day: 1
Enter the number of days elapsed since today: 3
Today is Monday and the future day is Thursday

Enter today's day: 0
Enter the number of days elapsed since today: 31
Today is Sunday and the future day is Wednesday
**/

public class TeamD_lab31 {
    static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        int today = 0;
        int future = 0;
        int process = 0;
        
        String stringToday ="";
        String stringFuture = "";
        System.out.print("Enter today's day: ");
        today = sc.nextInt();
        
        while(today>6 || today<0)
        {
            System.out.print("Enter today's day: ");
            today = sc.nextInt();
        }
        
        System.out.print("Enter the number of days elapsed since today: ");
        future = sc.nextInt();
        
        while(future<0)
        {
            System.out.print("Enter the number of days elapsed since today: ");
            future = sc.nextInt();
        }
        
        process = (future + today)%7;
        
        if(today == 0)
            stringToday = "Sunday";
        else if(today == 1)
            stringToday = "Monday";
        else if(today == 2)
            stringToday = "Tuesday";
        else if(today == 3)
            stringToday = "Wednesday";
        else if(today == 4)
            stringToday = "Thursday";
        else if(today == 5)
            stringToday = "Friday";
        else if(today == 6)
            stringToday = "Saturday";
        else
            System.out.println("Incorrect value for today's day");
        
        
        if(process == 0)
            stringFuture = "Sunday";
        else if(process == 1)
            stringFuture = "Monday";
        else if(process == 2)
            stringFuture = "Tuesday";
        else if(process == 3)
            stringFuture = "Wednesday";
        else if(process == 4)
            stringFuture = "Thursday";
        else if(process == 5)
            stringFuture = "Friday";
        else if(process == 6)
            stringFuture = "Saturday";
        else
            System.out.println("Incorrect value for future's day");
        
        System.out.printf("Today is %s and the future day is %s%n",stringToday,stringFuture);
        
    }
    
}
