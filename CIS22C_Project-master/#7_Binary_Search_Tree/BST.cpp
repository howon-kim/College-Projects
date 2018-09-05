//
//  BST.cpp
//  Binary_Search_Tree
//
//  Created by HOWON KIM on 3/1/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "BST.h"
using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    
    infile.open("input.txt");
    outfile.open("output.txt");
    
    if(!infile)
    {
        cout << "File Open Error" << endl;
        exit(111);
    }
    

    string input;

    
    while(getline(infile, input))
    {
        
        BST<int> tree;
        cout.rdbuf(outfile.rdbuf()); // Redirect cout to out.txt

        // FIRST LINE START
        stringstream stream1(input);
        
        while(1)
        {
            int n;
            stream1 >> n;
            if(!stream1)
                break;
            tree.add(n);
        }



        //streambuf *coutbuf = cout.rdbuf(); // Save old buf
        //cout.rdbuf(coutbuf); // Reset to standard output again


        tree.preOrderPrint();
        tree.inOrderPrint();

        
        
        // SECOND LINE START
        getline(infile, input);
        stringstream stream2(input);
        
        while(1)
        {
            int n;
            stream2 >> n;
            if(!stream2)
                break;
            
            if(tree.search(n))
            {
                cout << n << " was found in the BST" << endl;
                tree.remove(n);
            }
            else
                cout << n << " was not found in the BST" << endl;
        }
        
        
        // THIRD LINE START
        getline(infile, input);
        stringstream stream3(input);
        
        while(1)
        {
            int n;
            stream3 >> n;
            if(!stream3)
                break;
            tree.add(n);
        }
        tree.postOrderPrint();
        
        cout << "The size of the BST is " << tree.getSize() << endl;
        cout << "The height of the BST is " << tree.getHeight() << endl;
        cout << endl;
        
    }
    
    infile.close();
    outfile.close();
    
    return 0;
}