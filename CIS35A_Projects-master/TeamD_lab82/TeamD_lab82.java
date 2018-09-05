/*
Write a program that inserts 25 random integers from 0 to 100 in order into a LinkedList object.
The program should sort the elements, then calculate the sum of the elements and the floating-point average of the elements.

Sample run

[6, 12, 12, 18, 20, 30, 35, 36, 44, 51, 53, 53, 54, 57, 63, 67, 68, 69, 72, 76, 77, 77, 80, 86, 95]
Sum is: 1311
Average is: 52.44
 */

package teamd_lab82;

import java.util.LinkedList;
import java.lang.Math;
import java.util.Collections;

/**
 * Lab 8.2
 * @author HWKIM
 */
public class TeamD_lab82 {

    public static void main(String[] args) {
        
        LinkedList<Integer> list = new LinkedList<>();
        int sum = 0;
        double average = 0;

        // Create the list
        for(int i = 0; i < 25; i++)
        {
            int random = ((int)(Math.random() * 1000) % 101);
            list.add(random);
        }
        
        Collections.sort(list);  // Sort the list
        
        // Print the list
        for(int i = 0; i < list.size(); i++)
        {
            sum += list.get(i); // Calculate Sum
            
            if(i == 0)
                System.out.printf("[%d, ",list.get(i));
            else if(i == list.size() -1)
                System.out.printf("%d]\n",list.get(i));
            else
                System.out.printf("%d, ",list.get(i));  
        }
        
        
        // Calculate Average
        average = (double)sum / list.size();
        
        // Print result
        System.out.printf("Sum is: %d\n", sum);
        System.out.printf("Average is: %.2f\n", average);
   
    }    
}
