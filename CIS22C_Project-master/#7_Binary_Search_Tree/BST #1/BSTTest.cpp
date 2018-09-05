//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by HOWON KIM on 2/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, const char * argv[]) {

    
    BST<int> bst;
        // cout << "Root of tree: " << bst.getRoot() << endl; // Error Message

    bst.add(100);
    cout << "Root of tree: " << bst.getRoot() << endl;
    
    bst.add(70);
    bst.add(40);

    bst.inOrderPrint();
    
    BST<int> test;
    
    test.add(13);
    test.add(3);
    test.add(4);
    test.add(12);
    test.add(14);
    test.add(10);
    test.add(5);
    test.add(1);
    test.add(8);
    test.add(2);
    test.add(7);
    test.add(9);
    test.add(11);
    test.add(6);
    test.add(18);







    test.inOrderPrint(); // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 18
    test.preOrderPrint(); // 13 3 1 2 4 12 10 5 8 7 6 9 11 14 18
    test.postOrderPrint(); // 2 1 6 7 9 8 5 11 10 12 4 3 18 14 13

    cout << "minimum : " << test.minimum() << endl;
    cout << "maximum : " << test.maximum() << endl;
    cout << "minimum : " << test.minimum() << endl;

    cout << "size : " << test.getSize() << endl;
    
    if(test.search(1)) // Value is exist
        cout << "Value is exist" << endl;
    else
        cout << "Value is not exist" << endl;
    

    if(test.isEmpty()) // Tree is not empty
        cout << "Tree is empty" << endl;
    else
        cout << "Tree is not empty" << endl;
    
    cout << "Height : " << test.getHeight() << endl;
    
    test.remove(100); // Not valid
    test.remove(10);
    test.inOrderPrint();  // 1 2 3 4 5 6 7 8 9 11 12 13 14 18
    test.remove(11);
    test.inOrderPrint();  // 1 2 3 4 5 6 7 8 9 12 13 14 18

    cout << "size : " << test.getSize() << endl; // 13

    BST<int> Ctest = test;
    Ctest.inOrderPrint(); // 1 2 3 4 5 6 7 8 9 12 13 14 18
 
    cout << "Copied tree size : " << Ctest.getSize() << endl; // 13

    
    
    
    return 0;
}

/** TEST OUTPUT 
 Root of tree: 100
 40 70 100
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 18
 13 3 1 2 4 12 10 5 8 7 6 9 11 14 18
 2 1 6 7 9 8 5 11 10 12 4 3 18 14 13
 minimum : 1
 maximum : 14
 minimum : 1
 size : 15
 Value is not exist
 Tree is not empty
 Height : 8
 1 2 3 4 5 6 7 8 9 11 12 13 14 18
 1 2 3 4 5 6 7 8 9 12 13 14 18
 size : 13
 1 2 3 4 5 6 7 8 9 12 13 14 18
 Copied tree size : 13
 Program ended with exit code: 0
 **/
