/*
Write a program that reads the integers between 1 and 100 and counts the occurences of each. 
Assume the input ends with 0.

Sample run. Note that if the number occurs more than one time, the plural word "times" is used in the output.

Enter the integers between 1 and 100: 2 5 6 5 4 3 23 43 2 0
2 occurs 2 times
3 occurs 1 time
4 occurs 1 time
5 occurs 2 times
6 occurs 1 time
23 occurs 1 time
43 occurs 1 time
 */

package teamd_lab61;
import java.util.Scanner;

/**
 * TEAM D
 * LAB 6.1
 * @author HWKIM
 */

public class TeamD_lab61 {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        
        int input = 1;
        int [] numbers = new int[101];
        
        // INPUT PROCESS
        System.out.print("Enter the integers between 1 and 100: ");
        while(input!=0)
        {
            input = sc.nextInt();
            
            if(input > 0 && input <= 100){
                numbers[input]++;
            }
        }
        
        // OUTPUT PROCESS
        for(int i = 0 ; i < 101 ; i++)
        {
            if(numbers[i] == 1){
                System.out.printf("%d occurs %d time\n", i, numbers[i]);
            }
            else if(numbers[i] > 1){
                System.out.printf("%d occurs %d times\n", i, numbers[i]);
            }
        }
    }
    
}
