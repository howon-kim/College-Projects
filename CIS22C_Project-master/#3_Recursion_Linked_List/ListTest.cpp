/**
 
 * Howon Kim
 
 * CIS 22C
 
 * ListTest.cpp
 
 */

#include <iostream>
#include "List.h"
using namespace std;


int main() {
    List<int> item;
    item.insert_last(5);
    item.insert_last(2);
    item.insert_last(3);
    item.insert_last(7);
    item.insert_last(9);

    cout << "It displays 9 7 3 2 5" << endl;
    item.printReverse();
    cout << endl;
    
    item.begin();
    cout << "It displays 5" << endl;
    cout << item.get_current() << endl;
    cout << endl;

    
    cout << "It displays 1" << endl;
    cout << item.getIndex() << endl;
    cout << endl;

    
    item.scroll();
    item.scroll();

    cout << "It displays 5 2 3 7 9" << endl;
    item.print();
    cout << endl;

    
    cout << "It displays 3" << endl;
    cout <<  item.getIndex() << endl;
    cout << endl;

    
    item.scrollToIndex(4);
    cout << "It displays 7" << endl;
    cout << item.get_current() << endl;
    cout << endl;


    item.scrollToIndex(3);
    cout << "It displays 3" << endl;
    cout << item.get_current() << endl;
    cout << endl;


    
    cout << "It displays 1" << endl;
    cout << item.linear_search(5) << endl;
    cout << endl;

    
    item.sorting();
    
    cout << "It displays 5" << endl;
    cout << item.binary_search(1, item.get_size(), 9) << endl;
    cout << endl;


    
    
    List<double> data;
    
    cout << "It displays the error message" << endl;
    data.printReverse();
    data.scrollToIndex(1);
    data.scrollToIndex(0);
    data.getIndex();
    data.linear_search(0);
    cout << endl;



    data.insert_last(1);
    data.insert_last(2);
    data.insert_last(3);
    data.insert_last(4);
    data.insert_last(5);
    
    data.scrollToIndex(0);
    cout << "It displays error message and -1(invalid index value)" << endl;
    cout << data.getIndex() << endl;;
    cout << endl;

    
    
    data.scrollToIndex(5);
    cout << "It displays 5" << endl;
    cout << data.getIndex() << endl;
    cout << endl;


    
    data.scrollToIndex(4);
    cout << "It displays 4" << endl;
    cout << data.getIndex() << endl;
    cout << endl;

    

    
    cout << "It displays 5 4 3 2 1" << endl;
    data.printReverse();
    cout << endl;


    
    cout << "It returns -1(invalid index value)" << endl;
    cout << data.linear_search(0) << endl;
    cout << data.linear_search(4.4) << endl;
    cout << endl;


    cout << "It displays 1" << endl;
    cout << data.linear_search(1) << endl;
    cout << endl;

    
    cout << "It displays 3" << endl;
    cout << data.linear_search(3) << endl;
    cout << endl;

    
    cout << "It displays 5" << endl;
    cout << data.linear_search(5) << endl;
    cout << endl;


    
    List<int> data2;

    data2.insert_last(7);
    data2.insert_last(8);
    data2.insert_last(3);
    data2.insert_last(5);
    data2.insert_last(2);
    data2.insert_last(1);
    data2.insert_last(4);
    data2.insert_last(6);
    data2.insert_last(10);
    data2.insert_last(9);
    
    cout << "It displays 9 10 6 4 1 2 5 3 8 7" << endl;
    data2.printReverse();
    cout << endl;


    cout << "It returns -2(invalid index value) because it is not sorted" << endl;
    cout << data2.binary_search(1, data2.get_size(), 5) << endl;
    cout << endl;

    
    cout << "It displays 1 2 3 4 5 6 7 8 9 10" << endl;
    data2.sorting();
    cout << endl;

    
    cout << "It returns -1(invalid index value) because they can't find the data" << endl;
    cout << data2.binary_search(1, data2.get_size(), 11) << endl;
    cout << endl;

    
    
    cout << "It displays 10" << endl;
    cout << data2.binary_search(1, data2.get_size(), 10) << endl;
    cout << endl;

    cout << "It displays 1" << endl;
    cout << data2.binary_search(1, data2.get_size(), 1) << endl;
    cout << endl;

    cout << "It displays 2" << endl;
    cout << data2.binary_search(1, data2.get_size(), 2) << endl;
    cout << endl;



    return 0;
  }

/* OUTPUT

 It displays 9 7 3 2 5
 9 7 3 2 5
 
 It displays 5
 5
 
 It displays 1
 1
 
 It displays 5 2 3 7 9
 5 2 3 7 9
 
 It displays 3
 3
 
 It displays 7
 7
 
 It displays 3
 3
 
 It displays 1
 1
 
 The contents are :
 2 3 5 7 9
 It displays 5
 5
 
 It displays the error message
 printReverse() : List is empty
 scrollToIndex(int index) : List is empty
 scrollToIndex(int index) : List is empty
 getIndex() : Iterator is off the end of the List
 linear_search(listitem item) : List is empty
 
 scrollToIndex(int index) : Index is out of the range
 It displays error message and -1(invalid index value)
 getIndex() : Iterator is off the end of the List
 -1
 
 It displays 5
 5
 
 It displays 4
 4
 
 It displays 5 4 3 2 1
 5 4 3 2 1
 
 It returns -1(invalid index value)
 -1
 -1
 
 It displays 1
 1
 
 It displays 3
 3
 
 It displays 5
 5
 
 It displays 9 10 6 4 1 2 5 3 8 7
 9 10 6 4 1 2 5 3 8 7
 
 It returns -2(invalid index value) because it is not sorted
 binary_search(int low, int high, listitem item) : List is not sorted
 -2
 
 It displays 1 2 3 4 5 6 7 8 9 10
 The contents are :
 1 2 3 4 5 6 7 8 9 10
 
 It returns -1(invalid index value) because they can't find the data
 -1
 
 It displays 10
 10
 
 It displays 1
 1
 
 It displays 2
 2
 
 Program ended with exit code: 0
*/