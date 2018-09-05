/**
 CIS 22B - Homework 1: ARRAYS, FUNCTIONS and SORTING
 Project: Lucky Numbers
 
 Name: HOWON KIM
 IDE: XCODE 6.3 (MAC OS X 10.03)
 */


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPE
void inputFile(int id[], int lucky[], int SIZE, int &num);
void descendingSort(int idnum[], int luckynum[], int num);
void writeSortedArraysToFile(const int sortid[], const int sortlucky[], int num);
void sortLuckyNumbers(const int luckynumbers[], int sort_eList[], int sort_oList[], int sort_nList[], int num);
void writeThreeArraysToFile(const int write_eList[], const int write_oList[], const int write_nList[],int num);

int main()
{
    cout<<"START THE PROGRAM"<<endl
    <<"Made by HOWON KIM"<<endl<<endl;
    
    const int SIZE=50; // Maximum array size
    int num_id[SIZE]={0}; // Student ID
    int num_lucky[SIZE]={0}; // Lucky Number
    int num=0; // Actual array size
    
    int eList[SIZE]={0}; // Even number
    int oList[SIZE]={0}; // Odd number
    int nList[SIZE]={0}; // Negative number
    

    // Read Student ID and Lucky number
    cout<<"START THE Fuction inputFile :: "<<endl;
    inputFile(num_id, num_lucky, SIZE, num);
    
    /* CHECK THE DATA IS READ CORRECTLY *
    for(int i=0;i<num;i++)
    {
        cout<<num_id[i]<<" "
        <<num_lucky[i]<<endl;
    }
    */
    
    // Insertion sort : Sort the parallel arrays in descending order
    cout<<"START THE Fuction descendingSort :: "<<endl;
    descendingSort(num_id, num_lucky, num);
    
    // Write the sorted arrays to another file named sorted.txt
    cout<<"START THE Fuction writeSortedArraysToFile :: "<<endl;
    writeSortedArraysToFile(num_id, num_lucky, num);
    
    // Place the even, odd, negative number to separate array
    cout<<"START THE Fuction sortLuckyNumbers :: "<<endl;
    sortLuckyNumbers(num_lucky, eList, oList, nList, num);
    
    // Write the three arrays to a file named lucky.txt
    cout<<"START THE Fuction writeThreeArraysToFile :: "<<endl;
    writeThreeArraysToFile(eList, oList, nList,num);
    

    cout<<"Everything is Okay"<<endl
        <<"END THE PROGRAM";


}

// Read data from file
void inputFile(int id[], int lucky[], int SIZE, int &num)
{
    // Open file
    ifstream infile;
    infile.open("/Users/HWKIM/Desktop/22B_HW1_HOWONKIM/22B_HW1_HOWONKIM/numbers.txt");
    cout<<"Opened the numbers.txt"<<endl;

    // Read data from file until end of file
    cout<<"Read data from numbers.txt"<<endl;
    while(!infile.eof())
    {
        infile>>id[num];
        //cout<<"NUM_ID : "<<id[num]<<endl;
        
        infile>>lucky[num];
        //cout<<"NUM_LUCKY : "<<lucky[num]<<endl;
        
        num++; // for Actual array size
        
        // If more than 50 students, terminate program
        if(num>=SIZE)
        {
            cout<<"The file contains more than 50 lines!"<<endl;
            exit(0);
        }
    }
    // Close file
    infile.close();
    cout<<"Closed the number.txt"<<endl;
    cout<<"FINISH THE FUNCTION :: "<<endl<<endl;

    
    return;
}

// Insertion Sort function
void descendingSort(int idnum[], int luckynum[], int num)
{
    cout<<"Sorting the ID by descending order"<<endl;

    for (int curr = 1; curr < num; curr++)
    {
        int hold = idnum[curr]; // copy current element to hold
        int hold_lucky =luckynum[curr];
        int back = curr - 1;
        while (back >= 0 && hold > idnum[back])   // search where to insert the current element
        {
            idnum[back + 1] = idnum[back];        // shift to the right
            luckynum[back+1]=luckynum[back];
            back--;
        
        }
        idnum[back + 1] = hold; // put hold back to the array
        luckynum[back+1]=hold_lucky;
    }
    cout<<"FINISH THE FUNCTION :: "<<endl<<endl;
    return;
}

// Write data to file
void writeSortedArraysToFile(const int sortid[], const int sortlucky[], int num)
{
    int n=1;
    
    // Open file
    ofstream outfile;
    outfile.open("/Users/HWKIM/Desktop/22B_HW1_HOWONKIM/22B_HW1_HOWONKIM/sorted.txt");
    cout<<"Opened sorted.txt file"<<endl;

    cout<<"Write sorted ID, Lucky number to sorted.txt"<<endl;
    for(int i=0;i<num;i++)
    {
        // Go to next line
        if(i==n*4)
        {
            outfile<<endl;
            n+=1;
        }
        
        outfile<<sortid[i];
        outfile<<" ";
        outfile<<left<<setw(12)<<sortlucky[i];
        

    }
    
    // Close file
    outfile.close();
    cout<<"Closed the sorted.txt"<<endl;
    cout<<"FINISH THE FUNCTION :: "<<endl<<endl;

    return;
}

// Arrange Even, Odd, Negative Numbers
void sortLuckyNumbers(const int luckynumbers[], int sort_eList[], int sort_oList[], int sort_nList[], int num)
{
    int num_eList=0, num_oList=0, num_nList=0;
    cout<<"Place luckynumbers to Even, Odd, Negative arrays"<<endl;
    
    for(int i=0;i<num;i++)
    {
        if(luckynumbers[i]%2==0) // For Even number
        {
            sort_eList[num_eList]=luckynumbers[i];
            num_eList++;
        }
        if(luckynumbers[i]%2==1 || luckynumbers[i]%2==-1) // For Odd number
        {
            sort_oList[num_oList]=luckynumbers[i];
            num_oList++;
        }
        if(luckynumbers[i]<0) // For negative number
        {
            sort_nList[num_nList]=luckynumbers[i];
            num_nList++;
        }
    }
    cout<<"FINISH THE FUNCTION :: "<<endl<<endl;
    return;
}


// Write three arrays(eList, oList, nList) to file
void writeThreeArraysToFile(const int write_eList[], const int write_oList[], const int write_nList[],int num)
{
    // Open file
    ofstream writefile;
    writefile.open("/Users/HWKIM/Desktop/22B_HW1_HOWONKIM/22B_HW1_HOWONKIM/lucky.txt");
    cout<<"Opened the lucky.txt file"<<endl;

    
    writefile<<setw(12)<<"EVEN"<<setw(12)<<"ODD"<<setw(12)<<"NEGATIVE"<<endl;
    
    cout<<"Write the Odd, Even, Negative lucky number to the lucky.txt"<<endl;

    for(int i=0;i<num;i++)
    {
        // Even number
        if(write_eList[i]==0) // If no data, remain empty
        {
            writefile<<setw(12)<<"";
        }
        else // If data exist, enter data
        {
            writefile<<right<<setw(12)<<write_eList[i];
        }
        
        // Odd number
        if(write_oList[i]==0) // If no data, remain empty
        {
            writefile<<setw(12)<<"";
        }
        else // If data exist, enter data
        {
            writefile<<setw(12)<<write_oList[i];
        }
        
        // Negative number
        if(write_nList[i]==0) // If no data, remain empty
        {
            writefile<<setw(12)<<"";
        }
        else // If data exist, enter data
        {
            writefile<<setw(12)<<write_nList[i];
        }
        // Go to next line
        writefile<<endl;

    }
    // Close file
    writefile.close();
    cout<<"Closed the lucky.txt"<<endl;
    cout<<"FINISH THE FUNCTION :: "<<endl<<endl;
    
    return;
}

/* Output
 * CMD
 START THE PROGRAM
 
 START THE Fuction inputFile ::
 Opened the numbers.txt
 Read data from numbers.txt
 Closed the number.txt
 FINISH THE FUNCTION ::
 
 START THE Fuction descendingSort ::
 Sorting the ID by descending order
 FINISH THE FUNCTION ::
 
 START THE Fuction writeSortedArraysToFile ::
 Opened sorted.txt file
 Save sorted ID, Lucky number to sorted.txt
 Closed the sorted.txt
 FINISH THE FUNCTION ::
 
 START THE Fuction sortLuckyNumbers ::
 Place luckynumbers to Even, Odd, Negative arrays
 FINISH THE FUNCTION ::
 
 START THE Fuction writeThreeArraysToFile ::
 Opened the lucky.txt file
 Write the Odd, Even, Negative lucky number to the lucky.txt
 Closed the lucky.txt
 FINISH THE FUNCTION ::
 
 END THE PROGRAM
 
 * sorted.txt
 9999 1213121     9518 -9          9393 98          9191 88
 9088 -12         9002 18          8928 -9          8480 -18
 8280 1           7880 -6          7788 50          7714 29
 7655 75          6786 808         6658 17          6621 907
 6547 18          6037 13          5677 1           5325 1024
 5123 19          4770 -2          4751 53          4012 6
 3993 -280        3939 -121        3434 -223        3333 -2
 3228 99          3199 97          2012 -27         2000 91
 1919 12          1422 86          1412 15          1234 -8
 1222 -13         1219 73          1012 -5          1010 -3

 * lucky.txt
 EVEN         ODD    NEGATIVE
   98     1213121          -9
   88          -9         -12
  -12          -9          -9
   18           1         -18
  -18          29          -6
   -6          75          -2
   50          17        -280
  808         907        -121
   18          13        -223
 1024           1          -2
   -2          19         -27
    6          53          -8
 -280        -121         -13
   -2        -223          -5
   12          99          -3
   86          97
   -8         -27
               91
               15
              -13
               73
               -5
               -3
*/