/**
 
 * Howon Kim
 
 * CIS 22C
 
 * ListTest.cpp
 
 */

#include <iostream>
#include "List.h"
using namespace std;


int main() {
    List<int> listInt;
    List<int> listInt2;
    List<double> listDouble;
    List<string> listString;
    List<char> listChar;
    
    // When listInt is empty, it shows the error
    // listInt.begin();
    // listInt.scroll();
    
    listInt.insert_first(1);
    listInt.print(); // 1
    listInt.insert_first(2);
    listInt.print(); // 2 1
    listInt.insert_last(3);
    listInt.print(); // 2 1 3
    
    
    cout << "SIZE : " << listInt.get_size() << endl; // 3
    listInt.begin();
    cout << "Current data : " << listInt.get_current() << endl;  // 2
    
    cout << "First data : " << listInt.get_first() << endl; //2
    cout << "Last data : " << listInt.get_last() << endl; //3
    
    listInt.insert_current(4);
    listInt.print(); // 2 4 1 3
    
    cout << "Current data : " << listInt.get_current() << endl;  // 2
    listInt.scroll();
    cout << "Current data : " << listInt.get_current() << endl;  // 4
    listInt.scroll();
    cout << "Current data : " << listInt.get_current() << endl;  // 1
    listInt.scroll();
    cout << "Current data : " << listInt.get_current() << endl;  // 3
    
    
    listInt.insert_current(5);
    listInt.print(); // 2 4 1 3 5
    cout << "Last data : " << listInt.get_last() << endl; //5

    
    cout << "Current data : " << listInt.get_current() << endl;  // 3

    cout << "SIZE : " << listInt.get_size() << endl; // 5

    listInt.remove_first();
    listInt.print(); // 4 1 3 5
    cout << "First data : " << listInt.get_first() << endl; //4
    cout << "Last data : " << listInt.get_last() << endl; //5
    cout << "SIZE : " << listInt.get_size() << endl; // 4


    
    listInt.remove_last();
    listInt.print(); // 4 1 3
    cout << "SIZE : " << listInt.get_size() << endl; // 3
    
    listInt.insert_last(6);
    listInt.print(); // 4 1 3 6
    cout << "SIZE : " << listInt.get_size() << endl; // 4
    cout << "Current data : " << listInt.get_current() << endl;  // 3
    
    listInt.remove_first();
    listInt.print(); // 1 3 6
    
    listInt.delete_current();
    listInt.print(); // 1 6
    cout << "SIZE : " << listInt.get_size() << endl; // 2
    // cout << "Current data : " << listInt.get_current() << endl;  // ERROR
    
    listInt.begin();
    cout << "Current data : " << listInt.get_current() << endl;  // 1


    if(listInt==listInt2) // different
        cout << "same" << endl;
    else
        cout << "different" << endl;
    
    listInt2.insert_first(1);
    listInt2.insert_last(6);
    
    
    if(listInt==listInt2) // same
        cout << "same" << endl;
    else
        cout << "different" << endl;

    
    listDouble.insert_first(1.1);
    listDouble.insert_first(2.2);
    listDouble.print(); // 2.2 1.1
    
    listChar.insert_last('a');
    listChar.insert_last('b');
    listChar.print(); // a b
    
    listString.insert_last("AB");
    listString.begin();
    listString.insert_current("CD");
    listString.insert_first("00");
    listString.print(); // 00 AB CD
    
    List<string> listString2(listString);
    listString2.print();
    
    cout << "Current data : " << listString.get_current() << endl;  // AB
    // cout << "Current data : " << listString2.get_current() << endl;  // AB

    List<int> listInt3(listInt);
    listInt3.print(); // 1 6
    cout << "SIZE : " << listInt3.get_size() << endl; // 2

    



    // SAMPLE
    List<int> Lint;
    List<char> Lchar;
    List<double> Ldouble;
    List<string> Lstring;
    
    cout << "Should print 3 error messages below iterator off end in pop_front, pop_back, current: \n";
    //will need to test these one-by-one as they should each call the exit() function.
    //comment out each one after it has been tested
    //Lint.remove_first();
    //Lint.remove_last();
    //Lint.delete_current();
    
    Lint.insert_first(5);
    cout << "Should print 5:\n";
    Lint.print();
    Lint.insert_last(6);
    cout << "Should print 5 6:\n";
    Lint.print();
    Lint.begin();
    Lint.insert_current(7);
    cout << "Should print 5 7 6:\n"; //note these should all print on a single line separated by spaces
    Lint.print();
    
    List<int> Lint2(Lint); //copy constructor
    cout << "Should print 5 7 6:\n";
    Lint2.print();
    
    cout << "Should print lists are equal: " << endl;
    if (Lint==Lint2)
     cout << "Lists are equal" << endl;
     else
     cout << "Lists are not equal" << endl;
    
    
    cout << "Size of list should be 0: "<< Lchar.get_size() << endl;
    Lchar.insert_first('a');
    Lchar.remove_first();
    cout << "Size of list should be 0: "<< Lchar.get_size() << endl;
    cout << "List should be empty. Nothing printed to screen: "<< endl;
    //Should print nothing and move to a new line.
    //Should NOT print an error message or any other message
    Lchar.print();
    
    cout << "Should print error message for scroll iterator is off the end of the list: \n";
   //Ldouble.scroll();
    cout << "Should print error message that iterator off the end of list in insert: \n";
   //Ldouble.insert_current(-8.9); //should not insert this value
    
    Ldouble.insert_last(8.8);
    Ldouble.insert_last(9.9);
    cout << "Should print 8.8 9.9:\n";
    Ldouble.print();
    
    cout << "Should print iterator is off the end of the List:\n";
    if(Ldouble.off_end())
    {
        cout <<"Iterator is off end\n";
    }
    else
    {
        cout << "Iterator is not off end\n";
    }
    Ldouble.begin();
    Ldouble.scroll();
    cout << "Should print 9.9:\n";
    cout << Ldouble.get_current() << endl;
    Ldouble.scroll();
    //cout << "Should print error message when calling current iterator off end:\n";
    //cout << Ldouble.get_current() << endl;
    Ldouble.remove_last();
    cout << "Should print 8.8:\n";
    Ldouble.print();
     
     

}

/* output
 1
 2 1
 2 1 3
 SIZE : 3
 Current data : 2
 First data : 2
 Last data : 3
 2 4 1 3
 Current data : 2
 Current data : 4
 Current data : 1
 Current data : 3
 2 4 1 3 5
 Last data : 5
 Current data : 3
 SIZE : 5
 4 1 3 5
 First data : 4
 Last data : 5
 SIZE : 4
 4 1 3
 SIZE : 3
 4 1 3 6
 SIZE : 4
 Current data : 3
 1 3 6
 1 6
 SIZE : 2
 Current data : 1
 different
 same
 2.2 1.1
 a b
 00 AB CD
 00 AB CD
 Current data : AB
 Current data : AB
 1 6
 SIZE : 2
 Should print 3 error messages below iterator off end in pop_front, pop_back, current:
 Should print 5:
 5
 Should print 5 6:
 5 6
 Should print 5 7 6:
 5 7 6
 Should print 5 7 6:
 5 7 6
 Should print lists are equal:
 Lists are equal
 Size of list should be 0: 0
 Size of list should be 0: 0
 List should be empty. Nothing printed to screen:
 
 Should print error message for scroll iterator is off the end of the list:
 Should print error message that iterator off the end of list in insert:
 Should print 8.8 9.9:
 8.8 9.9
 Should print iterator is off the end of the List:
 Iterator is off end
 Should print 9.9:
 9.9
 Should print error message when calling current iterator off end:
 Should print 8.8:
 8.8
*/