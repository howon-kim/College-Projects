/*
Create two priority queues, 
{ "George" , "Jim" , "John" , "Blake" , "Kevin" , "Michael" } and 
{ "George" , "Katie" , "Kevin" , "Michelle" , "Ryan" }, and find their union, difference, and intersection.

Sample run

The union of the two priority queue is [Blake, George, George, Jim, Kevin, Michael, John, Katie, Kevn, Michelle, Ryan ]
The difference of the two priority queue is [Blake, Jim, John, Michael]
The intersection of the two priority queue is [George, Kevin]
 */

package teamd_lab83;

/**
 * Lab 8.3
 * @author HWKIM
 */

import java.util.PriorityQueue;

public class TeamD_lab83 {
    public static void main(String[] args) {
        PriorityQueue<String> list1 = new PriorityQueue<>();
        PriorityQueue<String> list2 = new PriorityQueue<>();
        PriorityQueue<String> temp = new PriorityQueue<>();

        // Save the values
        list1.offer("George");
        list1.offer("Jim");
        list1.offer("John");
        list1.offer("Blake");
        list1.offer("Kevin");
        list1.offer("Michael");
        
        list2.offer("George");
        list2.offer("Katie");
        list2.offer("Kevin");
        list2.offer("Michelle");
        list2.offer("Ryan");
        
        // Process the values
        temp.addAll(list1);
        temp.addAll(list2);
        System.out.printf("The union of the two priority queue is %s\n", temp);
        
        temp.clear();
        temp.addAll(list1);
        temp.removeAll(list2);
        System.out.printf("The difference of the two priority queue is %s\n", temp);

        temp.clear();
        temp.addAll(list1);
        temp.retainAll(list2);
        System.out.printf("The intersection of the two priority queue is %s\n", temp);
    }
}

