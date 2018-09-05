/**
  Programming Assignment #3
  Pointers, Arrays and Dynamic Allocation of Memory
  Project: TEST SCORES STATISTICS

  // PLACE YOUR NAME HERE
*/

#include <iostream>
#include <fstream>

using namespace std;

void insertionSort(int array[], int size);

int main()
{

    return 0;
}

//**************************************************************
// Definition of function insertionSort.
// This function performs an ascending order insertion sort on
// array. size is the number of elements in the array.
//**************************************************************
            // NOTE: - curr and back are indices: they should be replaced by pointers
            //       - the first parameter should also be changed to a pointer
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
    return;
}

