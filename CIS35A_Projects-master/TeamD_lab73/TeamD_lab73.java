/*
Write the following method that returns the sum of all numbers in an ArrayList.

    public static void sort(ArrayList<Integer> list)
    public static int sum(ArrayList<Integer> list)

Write a test program that prompts the user to enter a series of numbers (use any sentinel to end such as 0 or negative numbers), 
stores them in an array list, and displays them in increasing order and their sum.

Sample run

Enter five integers: 84 5 12 5 9
5 5 9 12 84
The sum is 115
*/
package teamd_lab73;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Team D
 * Lab 7.3
 * @author HWKIM
 */

public class TeamD_lab73 {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        
        int input = 1;
        ArrayList<Integer> list = new ArrayList<Integer>();
        System.out.print("Enter the series of numbers (0 or negative number to finish input): ");
        
        while(input>0)
        {
            input = sc.nextInt();
            if(input>0)
                list.add(input);
        }
        
        sort(list);
        
        for(int i = 0; i < list.size(); i++)
        {
            System.out.printf("%d ", list.get(i));
        }
        System.out.println();
        System.out.printf("The sum is %d\n",sum(list));
    }
    
    public static void sort(ArrayList<Integer> sort)
    {
        int min;
   
        for (int i = 0; i < sort.size(); ++i) {
            min = i;
            for (int j = i + 1; j < sort.size(); ++j) {
                if (sort.get(j) < sort.get(min)) {
                    min = j;
                }
            }

            int temp = sort.get(i);
            sort.set(i, sort.get(min));
            sort.set(min, temp);  
        }
    }
    
    public static int sum(ArrayList<Integer> list){
        
        int sum = 0;
        
        for (int i = 0; i < list.size(); i++) {
            sum += list.get(i);
        }
        
        return sum;
    }
}

