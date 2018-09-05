/**
 Programming Assignment #3
 Pointers, Arrays and Dynamic Allocation of Memory
 Project: TEST SCORES STATISTICS
 
 // PLACE YOUR NAME HERE : HOWON KIM
 // IDE : XCODE 6.3.1 (MAC OS X 10.04)
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function Prototype
int  *readScores(int &rsize);
void insertionSort(int *const iptr, int isize);
void writeSortedScores(const int *const wptr, const int wsize, int count);
void calcLowestHighestScore(const int *const lhptr, const int lhsize, int &lhlowest, int &lhhighest);
void calcStandardDeviationAndAverage(const int *const daptr, const int dasize, double &daaverage, double &dastdeviation);
void displayResult(int dlowest, int dhighest, double daverage, double dstdeviation);


int main()
{
    // Declare variables
    int size = 0;
    int lowest = 0;
    int highest = 0;
    double average = 0;
    double stdeviation = 0;
    // Declare pointer
    int *ptr = nullptr;
    
    cout << "** Start the program **" << endl << endl;
    
    // Execute Functions
    cout << "** Start readScores Function **" << endl;
    ptr = readScores(size);
    /****** TEST CODE ******
     for(int i = 0 ; i<size ; i++)
     {
     cout << ptr[i] << " ";
     }
    ****** TEST CODE ******/
    cout << "** Finish readScores Function **" << endl << endl;
    
    cout << "** Start insertionSort Function **" << endl;
    insertionSort(ptr, size);
    /****** TEST CODE ******
     for(int i = 0 ; i<size ; i++)
     {
     cout << ptr[i] << " ";
     }
    ****** TEST CODE ******/
    cout << "** Finish insertionSort Function **" << endl << endl;
    
    cout << "** Start writeSortedScores Function **" << endl;
    writeSortedScores(ptr, size, 10);
    cout << "** Finish writeSortedScores Function **" << endl << endl;
    
    cout << "** Start calcLowestHighestScore Function **" << endl;
    calcLowestHighestScore(ptr, size, lowest, highest);
    cout << "** Finish calcLowestHighestScore Function **" << endl << endl;
    
    cout << "** Start calcStandardDeviationAndAverage Function **" << endl;
    calcStandardDeviationAndAverage(ptr, size, average, stdeviation);
    cout << "** Finish calcStandardDeviationAndAverage Function **" << endl << endl;
    
    cout << "** Start displayResult Function **" << endl;
    displayResult(lowest, highest, average, stdeviation);
    cout << "** Finish displayResult Function **" << endl << endl;
    
    cout << "** Delete the dynamically allocated arrays **" << endl << endl;
    delete [] ptr;
    cout << "** Finish the program **" << endl;
    return 0;
}
//**************************************************************
// Definition of function readScores.
// This function read integers from scores.txt file
// Input Parameter : none
// Output Parameter : rsize : size as the number of the scores
// Return Value : array : return address of the dynamically allocated arrays
//**************************************************************
int *readScores(int &rsize)
{
    // Declare Pointer
    int *array = nullptr;
    
    ifstream infile;
    // Open the file
    cout << ">> Open the scores.txt file" << endl;
    infile.open("/Users/HWKIM/Desktop/22B_KIM_HOWON_H3/22B_KIM_HOWON_H3/scores.txt");

    // File open error
    if(!infile)
    {
        cout << ">> Can't open the file" << endl;
        exit(111);
    }
    cout << ">> Complete to opened the scores.txt file" << endl;

    // Read size of array
    cout << ">> Read the size of array" << endl;
    infile >> rsize;
    cout << ">> Complete to read the size of array --> size : " << rsize << endl;

    
    // Make dynamically allocated arrays
    array = new int [rsize];
    cout << ">> Declared dynamically allocated arrays" << endl;
    
    // Read scores and save it to dynamically allocated arrays
    cout << ">> Read the scores and save to dynamically allocated arrays" << endl;
    for(int i = 0 ; i<rsize ; i++)
    {
        infile >> array[i];
    }
    cout << ">> Complete to save the scores" << endl;
    
    infile.close();
    cout << ">> Closed the scores.txt file" << endl;
   
    return array;
}

//**************************************************************
// Definition of function insertionSort.
// This function performs an ascending order insertion sort on
// array. size is the number of elements in the array.
// Input Parameter : isize : size as the number of the scores
// Output Parameter : iptr : to access the scores
// Return Value : none
//**************************************************************
// NOTE: - curr and back are indices: they should be replaced by pointers
//       - the first parameter should also be changed to a pointer
void insertionSort(int *const iptr, int isize)
{
    for (int *curr = &iptr[1] ; curr < &iptr[isize] ; curr++)
    {
        int hold = *curr;                   // copy current element to hold
        int *back = curr - 1;
        while (back >= iptr && hold < *back)   // search where to insert the current element
        {
            back[1] = *back;        // shift to the right
            back--;
        }
        back[1] = hold;                   // put hold back to the array
    }

    return;
}


//**************************************************************
// Definition of function writeSortedScores.
// This function write sorted scores to sorted.txt file also display the sorted scores
// Input Parameter
// - wptr : access the scores
// - wsize : size as the number of the scores
// - count : size as 10 numbers per line
// Output Parameter : none
// Return Value : none
//**************************************************************
void writeSortedScores(const int *const wptr, const int wsize, int count)
{
    ofstream outfile;
    cout << ">> Make sorted.txt file" << endl;
    outfile.open("/Users/HWKIM/Desktop/22B_KIM_HOWON_H3/22B_KIM_HOWON_H3/sorted.txt");
    
    if(!outfile)
    {
        cout << "Can't open output file" << endl;
        exit(222);
    }
    cout << ">> Complete to made sorted.txt file" << endl;
    
    cout << ">> Save the sorted array 10 numbers per line to the sorted.txt file" << endl;
    for(int i=0; i<wsize; i++)
    {
        outfile << left << setw(5) << wptr[i];
        if((i+1) == count)
        {
            outfile << endl;
            count +=10;
        }
    }
    count = 10;
    
    cout << ">> Complete to saved the sorted.txt file" << endl;
    outfile.close();
    cout << ">> Closed the sorted.txt file" <<endl;
    
    cout << ">> Display the sorted array 10 numbers per line" << endl;
    for(int i=0; i<wsize; i++)
    {
        cout << left << setw(5) << wptr[i];
        if((i+1) == count)
        {
            cout << endl;
            count +=10;
        }
    }
    cout << endl << ">> Complete to displayed the sorted array 10 numbers per line" << endl;
    

    return;
}

//**************************************************************
// Definition of function calcLowestHighestScore.
// This function calculate the Lowest score and Highest score
// Input Parameter
// - lhptr : access the scores
// - lhsize : size as the number of the scores
// Output Parameter
// - lhlowest : save lowest score
// - lhhighest : save highest score
// Return Value : none
//**************************************************************
void calcLowestHighestScore(const int *const lhptr, const int lhsize, int &lhlowest, int &lhhighest)
{
    // Initialize Variables
    lhlowest = *lhptr;
    lhhighest = *lhptr;
    
    cout << ">> Start to calculate the lowest score and highest score" << endl;
    for(int i=0; i<lhsize; i++)
    {
        if(lhptr[i] > lhhighest)
        {
            lhhighest = lhptr[i];
        }
        
        if(lhptr[i] < lhlowest)
        {
            lhlowest = lhptr[i];
        }
    }
    cout << ">> Complete to calculated the lowest score and highest score" << endl;
    
    return ;
}


//**************************************************************
// Definition of function calcStandardDeviationAndAverage.
// This function calculate the Standard deviation and Average
// Input Parameter
// - daptr : access the scores
// - dasize : size as the number of the scores
// Output Parameter
// - daaverage : save average score
// - dastdeviation : save standard deviation score
// Return Value : none
//**************************************************************
void calcStandardDeviationAndAverage(const int *const daptr, const int dasize, double &daaverage, double &dastdeviation)
{
    // Declare and Initialize variable
    double sum=0;
    
    cout << ">> Calculate the sum of the scores" << endl;
    for (int i=0; i<dasize; i++)
    {
        sum += daptr[i];
    }
    cout << ">> Finish to calculated the sum of the scores" << endl;
    
    cout << ">> Calculate the average of the scores" << endl;
    daaverage = sum / dasize;
    cout << ">> Finish to calculated the average of the scores" << endl;
    sum = 0;
    
    cout << ">> Calculate the special sum for standard deviation" << endl;
    for (int i=0; i<dasize; i++)
    {
        sum += pow((daptr[i] - daaverage),2);
    }
    cout << ">> Finish to calculated the special sum for standard deviation" << endl;
    
    cout << ">> Calculate the standard deviation" << endl;
    dastdeviation = sqrt(sum / (dasize-1));
    cout << ">> Finish to calculated the standard deviation" << endl;
    
    return ;
}

//**************************************************************
// Definition of function displayResult.
// This function display the lowest, highest, average, standard deviation
// Input Parameter
// - dlowest : lowest score
// - dhighest : highest score
// - daverage : average score
// - dstdeviation : standard deviation
// Output Parameter : none
// Return Value : none
//**************************************************************
void displayResult(int dlowest, int dhighest, double daverage, double dstdeviation)
{
    cout << ">> Average : " << fixed << setprecision(2) << daverage << endl;
    cout << ">> Lowest : " << dlowest << endl;
    cout << ">> Highest : " << dhighest << endl;
    cout << ">> Standard Deviation : " << fixed << setprecision(2) << dstdeviation << endl;

    return ;
}

/* OUTPUT
 Last login: Mon May 11 15:06:34 on ttys000
 /Users/HWKIM/Library/Developer/Xcode/DerivedData/22B_KIM_HOWON_H3-grlsjdstaxhjcyeymuuvazbvalik/Build/Products/Debug/22B_KIM_HOWON_H3 ; exit;
 admin:~ HWKIM$ /Users/HWKIM/Library/Developer/Xcode/DerivedData/22B_KIM_HOWON_H3-grlsjdstaxhjcyeymuuvazbvalik/Build/Products/Debug/22B_KIM_HOWON_H3 ; exit;
 ** Start the program **
 
 ** Start readScores Function **
 >> Open the scores.txt file
 >> Complete to opened the scores.txt file
 >> Read the size of array
 >> Complete to read the size of array --> size : 46
 >> Declared dynamically allocated arrays
 >> Read the scores and save to dynamically allocated arrays
 >> Complete to save the scores
 >> Closed the scores.txt file
 ** Finish readScores Function **
 
 ** Start insertionSort Function **
 ** Finish insertionSort Function **
 
 ** Start writeSortedScores Function **
 >> Make sorted.txt file
 >> Complete to made sorted.txt file
 >> Save the sorted array 10 numbers per line to the sorted.txt file
 >> Complete to saved the sorted.txt file
 >> Closed the sorted.txt file
 >> Display the sorted array 10 numbers per line
 56   64   65   67   67   68   72   73   74   76
 77   77   78   79   80   81   84   84   85   85
 85   85   86   86   87   88   88   89   90   92
 92   92   93   93   93   94   95   96   96   96
 97   97   97   99   100  100
 >> Complete to displayed the sorted array 10 numbers per line
 ** Finish writeSortedScores Function **
 
 ** Start calcLowestHighestScore Function **
 >> Start to calculate the lowest score and highest score
 >> Complete to calculated the lowest score and highest score
 ** Finish calcLowestHighestScore Function **
 
 ** Start calcStandardDeviationAndAverage Function **
 >> Calculate the sum of the scores
 >> Finish to calculated the sum of the scores
 >> Calculate the average of the scores
 >> Finish to calculated the average of the scores
 >> Calculate the special sum for standard deviation
 >> Finish to calculated the special sum for standard deviation
 >> Calculate the standard deviation
 >> Finish to calculated the standard deviation
 ** Finish calcStandardDeviationAndAverage Function **
 
 ** Start displayResult Function **
 >> Average : 84.74
 >> Lowest : 56
 >> Highest : 100
 >> Standard Deviation : 10.97
 ** Finish displayResult Function **
 
 ** Delete the dynamically allocated arrays **
 
 ** Finish the program **
 logout
 
 [Process completed]
 

 */