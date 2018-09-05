//
//  Assignment 11 : Grade Book
//  KimHowon_a11.cpp
//  Environment : MAC OSX 10.3 (XCODE 6.2)
//
//  Created by HOWON KIM on 3/22/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// FUNCTION PROTOTYPE
void enterNameScoreAndCalculateTotalScore(string[],double[],int);
void calculateAverageScore(double[],const double[],int );
void calculateGrade(const double[],char[],int );
void displayGradeScore(const string[],const double[],const char[],int);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // DECLARE VARIABLES
    const int NUMSTUDENT=5;
    string name[NUMSTUDENT];
    double avgscore[NUMSTUDENT]={0.0};
    double sumscore[NUMSTUDENT]={0.0};
    char grade[NUMSTUDENT];

    
    enterNameScoreAndCalculateTotalScore(name, sumscore,NUMSTUDENT);
    calculateAverageScore(avgscore,sumscore, NUMSTUDENT);
    calculateGrade(avgscore, grade, NUMSTUDENT);
    displayGradeScore(name, avgscore, grade, NUMSTUDENT);

    return 0;
}

// ENTER NAME, SCORE, AND CALCULATE AVERAGE SCORE
void enterNameScoreAndCalculateTotalScore(string fname[],double fsumscore[],int FNUMSTUDENT)
{
    // DECLARE VARIABLES
    const int NUMTEST=4;
    double student1[NUMTEST]={0.0};
    double student2[NUMTEST]={0.0};
    double student3[NUMTEST]={0.0};
    double student4[NUMTEST]={0.0};
    double student5[NUMTEST]={0.0};

    
for(int start=0;start<FNUMSTUDENT;start++)
{
    cout<<"Enter the student name : ";
    getline(cin,fname[start]);
    switch(start)
    {
        case 0:
            for(int index=0;index<NUMTEST;index++)
            {
                cout<<"Enter the "<<index+1<<" test score : ";
                cin>>student1[index];
                while(student1[index]<0 || student1[index]>100)
                {
                    cout<<"Do not accept test scores less than 0 or greater than 100"<<endl
                        <<"Enter the "<<index+1<<" test score : ";
                    cin>>student1[index];
                }
                fsumscore[start]+=student1[index];
                cin.ignore();
                }
            cout<<endl;
            break;
            
                
            case 1:
                for(int index=0;index<NUMTEST;index++)
                {
                    cout<<"Enter the "<<index+1<<" test score : ";
                    cin>>student2[index];
                    while(student2[index]<0 || student2[index]>100)
                    {
                        cout<<"Do not accept test scores less than 0 or greater than 100"<<endl
                            <<"Enter the "<<index+1<<" test score : ";
                        cin>>student2[index];
                    }
                    fsumscore[start]+=student2[index];
                    cin.ignore();

                }
            cout<<endl;
            break;
            
            case 2:
                for(int index=0;index<NUMTEST;index++)
                {
                    cout<<"Enter the "<<index+1<<" test score : ";
                    cin>>student3[index];
                    while(student3[index]<0 || student3[index]>100)
                    {
                        cout<<"Do not accept test scores less than 0 or greater than 100"<<endl
                            <<"Enter the "<<index+1<<" test score : ";
                        cin>>student3[index];
                    }
                    fsumscore[start]+=student3[index];
                    cin.ignore();

                }
            cout<<endl;
            break;
            case 3:
                for(int index=0;index<NUMTEST;index++)
                {
                    cout<<"Enter the "<<index+1<<" test score : ";
                    cin>>student4[index];
                    while(student4[index]<0 || student4[index]>100)
                    {
                        cout<<"Do not accept test scores less than 0 or greater than 100"<<endl
                            <<"Enter the "<<index+1<<" test score : ";
                        cin>>student4[index];
                    }
                    fsumscore[start]+=student4[index];
                    cin.ignore();

                }
            cout<<endl;
            break;
            case 4:
                for(int index=0;index<NUMTEST;index++)
                {
                    cout<<"Enter the "<<index<<" test score : ";
                    cin>>student5[index];
                    while(student5[index]<0 || student5[index]>100)
                    {
                        cout<<"Do not accept test scores less than 0 or greater than 100"<<endl
                            <<"Enter the "<<index+1<<" test score : ";
                        cin>>student5[index];
                    }
                    fsumscore[start]+=student5[index];
                    cin.ignore();

                }
            cout<<endl;
            break;
        }
    }
    return;
}

// CALCULATE AVERAGE SCORE
void calculateAverageScore(double favgscore[],const double ffsumscore[],int FNUMSTUDENT)
{
    for(int count=0;count<FNUMSTUDENT;count++)
    {
        favgscore[count]=ffsumscore[count]/4;
    }
    return;
}

// CALCULATE GRADE
void calculateGrade(const double ffavgscore[],char fgrade[],int FNUMSTUDENT)
{
    for(int numcount=0;numcount<FNUMSTUDENT;numcount++)
    {
        if(ffavgscore[numcount]>=90)
        {
            fgrade[numcount]='A';
        }
        else if(ffavgscore[numcount]>=80)
        {
            fgrade[numcount]='B';
        }
        else if(ffavgscore[numcount]>=70)
        {
            fgrade[numcount]='C';
        }
        else if(ffavgscore[numcount]>=60)
        {
            fgrade[numcount]='D';
        }
        else
        {
            fgrade[numcount]='F';
        }
    }
    return;
}


// DISPLAY PROCESS
void displayGradeScore(const string ffname[],const double fffavgscore[],const char ffgrade[],int FNUMSTUDENT)
{
for(int numstu=0;numstu<FNUMSTUDENT;numstu++)
    {
    cout<<"---- "<<ffname[numstu]<<"'s score ----"<<endl
    <<" Average Score : "<<fffavgscore[numstu]<<endl
    <<" Grade : "<<ffgrade[numstu]<<endl<<endl;
    }
    return;
}
