/**
  CIS 22B - Homework 1: ARRAYS, FUNCTIONS and SORTING
  Project: Lucky Numbers

  Name:
  IDE:
*/
#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(int array[], int size);

int main()
{
    // NOTE: Please replace the code given below by your own code
    int list[100] = {50, 30, 80, 10, 30, 40, 90, 30, 80, 30};
    int size = 10;

    // Display List
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    // SORT
    insertionSort(list, size);
    
    // Display List
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;


    return 0;
}

//**************************************************************
// Definition of function insertionSort.
// This function performs an ascending order insertion sort on
// array. size is the number of elements in the array.
//**************************************************************
void insertionSort(int array[], int size)
{
   for (int curr = 1; curr < size; curr++)
   {
      int hold = array[curr];                   // copy current element to hold
      int back = curr - 1;
      while (back >= 0 && hold < array[back])   // search where to insert the current element
      {
          array[back + 1] = array[back];        // shift to the right
          back--;
      }
      array[back + 1] = hold;                   // put hold back to the array
   }
}
