//
//  CListTest.cpp
//  Circular_Linked_List
//
//  Created by HOWON KIM on 1/25/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "CList.h"

int main(int argc, const char * argv[]) {

    List<int> temp;
    temp.insert_first(4);
    temp.insert_first(5);
    temp.insert_first(5);
    temp.print(); // 5 5 4
    
    temp.insert_last(6);
    temp.print(); // 5 5 4 6
    
    temp.insert_last(7);
    temp.print(); // 5 5 4 6 7
    
    
    cout << endl << "insert_last Test" << endl;
    List<int> temp2;
    temp2.insert_last(100);
    temp2.print(); // 100
    temp2.insert_last(200);
    temp2.print(); // 100 200
    temp2.insert_first(300);
    temp2.print(); // 300 100 200 
    
    
    temp2.remove_first();
    temp2.print(); // 100 200
    
    temp2.remove_last();
    temp2.print(); // 100
    
    temp2.remove_last();
    temp2.print(); //
    
    temp.print(); // 5 5 4 6 7
    
    temp.remove_last();
    temp.print(); // 5 5 4 6
    
    temp.remove_last();
    temp.print(); // 5 5 4
    
    temp.remove_last();
    temp.print(); // 5 5
    
    temp.remove_last();
    temp.print(); // 5
    
    temp.remove_last();
    temp.print(); //
    
    return 0;
}


/* OUTPUT

 5 5 4
 5 5 4 6
 5 5 4 6 7
 
 insert_last Test
 100
 100 200
 300 100 200
 100 200
 100
 5 5 4 6 7
 5 5 4 6
 5 5 4
 5 5
 5
*/