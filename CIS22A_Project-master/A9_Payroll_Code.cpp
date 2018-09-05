//
//  Assignment 9 : Payroll Code
//  KimHowon_a9.cpp
//  Environment : MAC OS X 10.03 (XCODE 6.1.1)
//
//  Created by HOWON KIM on 3/5/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // DECLARE VARIABLES
    ofstream outfile;
    ifstream infile;
    string code="";
    string read_code="";
    string read_salary="";
    string save_code="";
    string save_salary="";
    char sentinel;
    
    // OPEN FILE FOR OUTPUT
    outfile.open("/Users/HWKIM/Documents/KimHowon_a9/Payroll.txt");
    
    // WRITE DATA INTO THE FILE
    outfile
    <<"1#23400"<<endl
    <<"4#17000"<<endl
    <<"5#21000"<<endl
    <<"6#12600"<<endl
    <<"9#26700"<<endl
    <<"10#18900"<<endl
    <<"11#18500"<<endl
    <<"13#12000"<<endl
    <<"15#49000"<<endl
    <<"16#56500"<<endl
    <<"20#65000"<<endl
    <<"21#65500"<<endl
    <<"22#78200"<<endl
    <<"23#71000"<<endl
    <<"24#71100"<<endl
    <<"25#72000"<<endl
    <<"30#83000"<<endl
    <<"31#84000"<<endl
    <<"32#90000"<<endl;
    
    // CLOSE FILE
    outfile.close();

    
    // CALCULATION PROCESS
    do
    {
        // OPEN THE FILE FOR READ DATA
        infile.open("/Users/HWKIM/Documents/KimHowon_a9/Payroll.txt");

        // ENTER THE CODE FOR USER WANT TO FIND
        cout<<"Enter code : ";
        cin>>code;
        
        // FIND CODE FROM THE FILE DATA
        while(getline(infile,read_code,'#'))
        {
            getline(infile,read_salary);
            if(read_code==code)
            {
                save_code=read_code;
                save_salary=read_salary;
            }
      
        }
        
        // DISPLAY THE RESULT
        if(save_code==code)
        {
            cout<<"Code "<<save_code<<" Salary : "<<save_salary<<endl;
        }
        else
        {
            cout<<"There is no "<<code<<" in this file"<<endl;
        }
        
        // ASK TO EXIT PROGRAM
        cout<<"If you want to exit this program press N, If want to continue press anykey"<<endl;
        cin>>sentinel;
        
        // CLOSE FILE
        infile.close();

        
    }while(sentinel!='N');
    return 0;
}
