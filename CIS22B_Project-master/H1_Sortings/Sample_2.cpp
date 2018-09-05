/**
  CIS 22B - Homework 1: ARRAYS, FUNCTIONS, and SORTING
  Project B: An unusual sort
 
  Name:
  IDE:
*/

#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(int array[], int size);

int main()
{
    // Test your pogram using the following data:
    // SET ONE
    int a[100] = {30, 90, 10, 50, 20};
    int s[100] = { 0,  1,  2,  3,  4};
    int size = 5;
    /*
    // SET TWO
    int a[100] = {30, 90, 10, 50, 20, 30, 60, 15, 25, 70};
    int s[100] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9};
    int size = 10;
    */
    // SORT
    insertionSort(list, size);

    // WRITE original and sorted


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
