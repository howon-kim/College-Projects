/*
Write a program that randomly prompts the user to enter a capital for a state. 
Upon receiving the user input, the program reports whether the answer is correct. 
Assume that 50 states and their capitals are stored in a two-dimensional array. 
The program prompts the user to answer all states' capitals and displays the total correct count. 
The user's answer is not case sensitive.


What is the capital of Alabama? Juneau
The correct answer should be Montgomery
What is the capital of Arizona? Phoenix
Your answer is correct
What is the capital of Alaska?...
...
The correct count is 10
*/

package teamd_lab71;

import java.util.Scanner;
import java.lang.Math;


/**
 * Team D
 * Lab 7.1
 * @author HWKIM
 */

public class TeamD_lab71 {

public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {

        String[][] capital = {
            {"Alabama", "Montgomery"},
            {"Alaska", "Juneau"},
            {"Arizona", "Phoenix"},
            {"Arkansas", "Little Rock"},
            {"California", "Sacramento"},
            {"Colorado", "Denver"},
            {"Connecticut", "Hartford"},
            {"Delaware", "Dover"},
            {"Florida", "Tallahasse"},
            {"Georgia", "Atlanta"},
            {"Hawaii", "Honolulu"},
            {"Idaho", "Boise"},
            {"Illinois", "Springfield"},
            {"Indiana", "Indianapolis"},
            {"Iowa", "Des Moines"},
            {"Kansas", "Topeka"},
            {"Kentucky", "Frankfort"},
            {"Louisiana", "Baton Rouge"},
            {"Maine", "Augusta"},
            {"Maryland", "Annapolis"},
            {"Massachusettes", "Boston"},
            {"Michigan", "Lansing"},
            {"Minnesota", "Saint Paul"},
            {"Mississippi", "Jackson"},
            {"Missouri", "Jefferson City"},
            {"Montana", "Helena"},
            {"Nebraska", "Lincoln"},
            {"Nevada", "Carson City"},
            {"New Hampshire", "Concord"},
            {"New Jersey", "Trenton"},
            {"New York", "Albany"},
            {"New Mexico", "Santa Fe"},
            {"North Carolina", "Raleigh"},
            {"North Dakota", "Bismark"},
            {"Ohio", "Columbus"},
            {"Oklahoma", "Oklahoma City"},
            {"Oregon", "Salem"},
            {"Pennslyvania", "Harrisburg"},
            {"Rhode Island", "Providence"},
            {"South Carolina", "Columbia"},
            {"South Dakota", "Pierre"},
            {"Tennessee", "Nashville"},
            {"Texas", "Austin"},
            {"Utah", "Salt Lake City"},
            {"Vermont", "Montpelier"},
            {"Virginia", "Richmond"},
            {"Washington", "Olympia"},
            {"West Virginia", "Charleston"},
            {"Wisconsin", "Madison"},
            {"Wyoming", "Cheyenne"}
        };
    

        int count = 0;
        int count_answer = 0;
        int random = 0;
        String[][] answer = new String[capital.length][2];
        
        while(count != capital.length)
        {
            random = ((int)(Math.random() * 100) % capital.length);
            
            if(!capital[random][0].equals(answer[random][0]))
            {
                answer[random][0] = capital[random][0];

                System.out.printf("What is the capital of %s? ",capital[random][0]);
                answer[random][1] = sc.nextLine();
            
                
                if(answer[random][1].equalsIgnoreCase(capital[random][1]))
                    System.out.printf("Your answer is correct\n");
                else
                    System.out.printf("The correct answer should be %s\n",capital[random][1]);

                count++;
                
            }
        }

        for(int i = 0; i < answer.length; i++)
        {
            if(answer[i][1].equalsIgnoreCase(capital[i][1]))
                count_answer++;
        }
       
        System.out.printf("The correct count is %d\n",count_answer);
    }
}