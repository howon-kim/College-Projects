/*
You have a list of student ID’s followed by the course number (separated by a space) that the student is enrolled in. 
The listing is in no particular order. For example, if student 1 is in CS100 and CS200 while student 2 is in CS105 and MATH210 
then the list might look like this:

1 CS100
2 MATH210
2 CS105
1 CS200

Write a program that reads data in this format from the console. 
If the ID is -1 then stop inputting data. 
Use the HashMap class to map from an Integer (the student ID) to an ArrayList of type String that holds each class that the student is enrolled in. 
The declaration should look like this:

HashMap<> students = new HashMap<>();
After all data is input, iterate through the map and output the student ID and all classes stored in the vector for that student. 
The result should be a list of classes organized by student ID.

Sample run

Enter data in the format:  ID CourseNum
Enter -1 to end.Enter -1 to end.
1 CS100
2 MATH210
2 CS105
1 CS200
-1

Student: 1
CS100 CS200
Student: 2
MATH210 CS105
 */

package teamd_lab84;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.ArrayList;

/**
 * Lab 8.4
 * @author HWKIM
 */

public class TeamD_lab84 {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        
        HashMap<Integer, ArrayList<String>> students = new HashMap<>();
        Integer studentID = 0;
        
        // Print Description
        System.out.println("Enter data in the format: ID CourseNum");
        System.out.println("Enter -1 to end.");
        
        // Input the Key and Values to HashMap
        while(studentID != -1){
       
            ArrayList<String> course = new ArrayList<>();
            studentID = sc.nextInt();
            
            if(studentID != -1){
                if(students.containsKey(studentID)){
                    course = students.get(studentID);
                    course.add(sc.next());
                }
                else
                   course.add(sc.next());
                
                students.put(studentID,course);
            }
        }
         
        
        // Print the Key and Values from HashMap 
        for (Map.Entry<Integer, ArrayList<String>> student : students.entrySet()){
        
            System.out.printf("Student: %d\n", student.getKey());
            ArrayList<String> courseValues = student.getValue();
                
            for(int i = 0; i < courseValues.size(); i++){
                System.out.printf("%s ", courseValues.get(i));
            }
            
            System.out.println();
        }
    }
}
