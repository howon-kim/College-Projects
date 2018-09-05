/*
Write a static method getCommonStrings(ArrayList<String> list1, ArrayList<String> list2) 
that returns a new instance of ArrayList containing all of the strings common to both list1 and list2.

Write a test program that creates two lists and calls the method.
 */

package teamd_lab74;

import java.util.ArrayList;

/**
 * Team D
 * Lab 7.4
 * @author HWKIM
 */

public class TeamD_lab74 {

    public static void main(String[] args) {
        ArrayList<String> list1 = new ArrayList<>();
        ArrayList<String> list2 = new ArrayList<>();
        ArrayList<String> result = new ArrayList<>();

        list1.add("Home");
        list1.add("Company");
        list1.add("Work");
        list1.add("Play");
        list1.add("School");

        
        list2.add("Home");
        list2.add("School");
        list2.add("Company");
        list2.add("Work");
        
        result = getCommonStrings(list1,list2);
        
        for(int i = 0; i < result.size(); i++)
        {
            System.out.printf("%s ",result.get(i));
        }
        
        System.out.println();
        
    }
    
    public static ArrayList<String> getCommonStrings(ArrayList<String> list1, ArrayList<String> list2){
        
        ArrayList<String> result = new ArrayList<>();
        
        for(int i = 0; i < list1.size(); i++)
        {
            if(list2.contains(list1.get(i)))
            {
                result.add(list1.get(i));
            }
        }
        return result;
    }
}
