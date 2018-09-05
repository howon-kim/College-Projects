//
//  main.cpp
//  lab2
//
//  Created by HOWON KIM on 1/13/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "Q.h"
#include "List.h"
#include <cstddef>
#include <cstdlib>

using namespace std;

int main()
{
    
    Q temp;
    
    temp.enqueue(10);
    temp.print(); //10
    
    temp.enqueue(20);
    temp.print(); // 10 20
    
    temp.dequeue();
    temp.print(); // 20
    
    Q temp2 (temp);
    temp2.print(); // 20
    
    temp.dequeue();
    temp.print(); // " "
    
    temp.enqueue(100);
    temp.print(); // 100
    
    if(temp == temp2) // DIFFERENT
        cout << "SAME" << endl;
    else
        cout << "DIFFERENT" << endl;
    
    temp.print(); // 100
    temp2.print(); // 20
    
    temp2.dequeue();
    temp2.enqueue(100);
    
    temp.print(); //
    temp2.print();
    
    if(temp == temp2) // SAME
        cout << "SAME" << endl;
    else
        cout << "DIFFERENT" << endl;
    
    
    return 0;
}



