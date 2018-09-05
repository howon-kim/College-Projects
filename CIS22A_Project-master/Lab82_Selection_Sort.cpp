//
//  Lab 8.2 : Working with Selection Sort
//  TeamP_lab82.cpp
//  Environment : Mac OS X 10.03 (XCODE 6.2)
//
//  Created by HOWON KIM on 3/18/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

/* Write a program to perform sorts on integer arrays 
 * so that the integers are arranged from smallest to largest.
 * Use the following data stored in an array.
 * 23	0	45	-3	-78	  1	 -1	 9
 */


#include <iostream>
using namespace std;
int main()
{
    // DECRAE VARIABLES
    const int SIZE=8;
    int array[SIZE]={23,0,45,-3,-78,1,-1,9};
    int lowest=0;
    int location=0;
    
    // SORTING PROCESS
    for(int start=0;start<SIZE-1;start++)
    {
        lowest=array[start];
        location=start;

        for(int index=start+1;index<SIZE;index++)
        {
            if(array[index]<=lowest)
            {
                lowest=array[index];
                location=index;
            }
        }
        array[location]=array[start];
        array[start]=lowest;
        
    }
    
    // DISPLAY PROCESS
    for(int count=0;count<SIZE;count++)
    {
        cout<<array[count]<<endl;
    }
    
    return 0;
}

/* S_INDEX = INDEX METHOD */
/*
int main()
{
    const int SIZE=8;
    int array[SIZE]={293,783,293,-1,1,-1,203,203};
    int num_lowest=0;
    int index_lowest=0;
    
    
    
    for(int s_index=0;s_index<SIZE-1;s_index++)
    {
        num_lowest=array[s_index];
        for(int index=s_index;index<SIZE;index++)
        {
            if(array[index]<=num_lowest)
            {
                num_lowest=array[index];
                index_lowest=index;
                
            }
        }
        array[index_lowest]=array[s_index];
        array[s_index]=num_lowest;
        
    }
    
    for(int i=0;i<SIZE;i++)
    {
        cout<<array[i]<<endl;
    }

    
    return 0;
}
 */
