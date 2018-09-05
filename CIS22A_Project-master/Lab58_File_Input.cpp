//
//  Lab 5.8 : Working with File Input
//  TeamP_lab58.cpp
//
//  Created by HOWON KIM on 2/27/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    int num=0;

    // DECLARE FILE STREAM
    ofstream writeDataToOutputFile;
    ofstream writeDataToInputFile;
    ifstream readDataFromInputFile;

    
    // OPEN FILE
    writeDataToInputFile.open("/Users/HWKIM/Documents/TeamP_lab58/Input.txt");
    
    
    // OUTPUT DATA TO FILE
    writeDataToInputFile<<100<<endl
            <<23<<endl
            <<44<<endl
            <<78<<endl
            <<95<<endl
            <<91<<endl
            <<10<<endl
            <<2<<endl
            <<5<<endl
            <<4<<endl
            <<6<<endl
            <<8<<endl;
    
    // CLOSE FILE
    writeDataToInputFile.close();
    
    // OPEN FILE
    readDataFromInputFile.open("/Users/HWKIM/Documents/TeamP_lab58/Input.txt");
    writeDataToOutputFile.open("/Users/HWKIM/Documents/TeamP_lab58/Output.txt");

    
    // INPUT DATA AND OUTPUT DATA TO ANOTHER FILE
    if(readDataFromInputFile&&writeDataToOutputFile)
    {
        while(readDataFromInputFile>>num)
        {
            if(num%2==0)
            {
                writeDataToOutputFile<<num<<endl;
            }
        }
    }
    
    else
    {
        cout<<"No file"<<endl;
    }
    
    // CLOSE FILE
    readDataFromInputFile.close();
    writeDataToOutputFile.close();
    return 0;
}
