//
//  Lab 5.7 : Working with File Input
//  TeamP_lab57.cpp
//
//  Created by HOWON KIM on 2/26/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    int order=0;
    int num=0;
    int sum=0;
    int avg=0;
    
    // DECLARE STREAM OBJECT
    ofstream writefile;
    ifstream readfile;
    
    // OPEN THE FILE
    writefile.open("/Users/HWKIM/Documents/TeamP_lab57/Random.txt");
    
    // WRITE THE DATA
    writefile<<42<<endl
            <<468<<endl
            <<335<<endl
            <<501<<endl
            <<170<<endl
            <<725<<endl
            <<479<<endl
            <<359<<endl
            <<963<<endl
            <<465<<endl
            <<706<<endl
            <<146<<endl
            <<282<<endl
            <<828<<endl
            <<962<<endl
            <<492<<endl
            <<996<<endl
            <<943<<endl
            <<828<<endl
            <<437<<endl
            <<392<<endl
            <<605<<endl
            <<903<<endl
            <<154<<endl
            <<293<<endl
            <<383<<endl
            <<422<<endl
            <<717<<endl
            <<719<<endl
            <<896<<endl
            <<448<<endl
            <<727<<endl
            <<772<<endl
            <<539<<endl
            <<870<<endl
            <<913<<endl
            <<668<<endl
            <<300<<endl
            <<36<<endl
            <<895<<endl
            <<704<<endl
            <<812<<endl
            <<323<<endl
            <<334<<endl
            <<674<<endl
            <<665<<endl
            <<142<<endl
            <<712<<endl
            <<254<<endl
            <<869<<endl
            <<548<<endl
            <<645<<endl
            <<663<<endl
            <<758<<endl
            <<38<<endl
            <<860<<endl
            <<724<<endl
            <<742<<endl
            <<530<<endl
            <<779<<endl
            <<317<<endl
            <<36<<endl
            <<191<<endl
            <<843<<endl
            <<289<<endl
            <<107<<endl
            <<41<<endl
            <<943<<endl
            <<265<<endl
            <<649<<endl
            <<447<<endl
            <<806<<endl
            <<891<<endl
            <<730<<endl
            <<371<<endl
            <<351<<endl
            <<7<<endl
            <<102<<endl
            <<394<<endl
            <<549<<endl
            <<630<<endl
            <<624<<endl;
    
    // CLOSE FILE
    writefile.close();
    
    // OPEN THE FILE
    readfile.open("/Users/HWKIM/Documents/TeamP_lab57/Random.txt");
    
    // READ FILE
    if(readfile)
    {
    while(readfile>>num)
    {
        ++order;
        cout<<"The number of numbers in the file : " << order << " : ";
        cout<<num<<endl;
        sum+=num;
    }
        avg=sum/order;
        // OUTPUT PROCESS
        cout<<"The sum of all the numbers in the file : "<<sum<<endl;
        cout<<"The average of all the numbers in the file : "<<avg<<endl;
    }
    else
    {
    cout<<"No file"<<endl;
    }
    
    // CLOSE FILE
    readfile.close();
    

    return 0;
}
