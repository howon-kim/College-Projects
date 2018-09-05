/*
Write the following method that returns true if the list is already served in increasing order.

 public static boolean isSorted(int[] list)
Write a test program that prompts the suer to enter a list and displays whether the list is sorted or not.

Sample run. Note that the first number in the input indicates the number of the elements i the list. This number is not part of the list.

Enter the list: 8 10 1 5 16 61 9 11 1
The list is not sorted.

Enter the list: 10 1 2 3 4 4 5 6 7 9 10
The list is already sorted.
 */

package teamd_lab62;
import java.util.Scanner;
import java.util.Arrays;

/**
 * TEAM D
 * LAB 6.2
 * @author HWKIM
 */

public class TeamD_lab62 {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
       
        int[] list;
        int input;
        
        // INPUT PROCESS
        System.out.print("Enter the list: ");
        input = sc.nextInt();
        list = new int[input];

        for(int i = 0; i < list.length ; i++)
        {
            input = sc.nextInt();
            list[i] = input;
        }        
        
        // CHECK IS SORTED
        if(isSorted(list)){
            System.out.println("The list is already sorted");
        }
        else{
            System.out.println("The list is not sorted");
        }
    }
    
    public static boolean isSorted(int[] list){
      
        int[] temp = Arrays.copyOf(list, list.length);
        Arrays.sort(temp);
        
        return Arrays.equals(list, temp);
    }   
}
