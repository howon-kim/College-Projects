//
//  Class.cpp
//  #9_ClassDB_TeamProject
//
//  Created by HOWON KIM on 3/11/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include "Class.h"
#include "BST.h"
#include <iostream>

void Class::displayCategory()
{
    cout << left << setw(6) << "-----" << setw(10) << "-------" << setw(10) << "------" << setw(10)  << "--------" <<  setw(40) <<  "-------------------------------------" << setw(10) << "---------" << setw(10) << "-----" << setw(20) <<  "-------------------" << setw(10) << "-------" << setw(8) << "------" << setw(8) << "------" << setw(20) << "---------------" <<  setw(10)  << "--------" << setw(10) << "--------" << setw(10) <<  "--------" << endl;


    cout << left << setw(6) << "CRN" << setw(10) << "Subject" << setw(10) << "Course" << setw(10)  << "Section" <<  setw(40) <<  "Title" << setw(10) << "Status" << setw(10) << "Days" << setw(20) <<  "Time" << setw(10) << "Room" << setw(8) << "Campus" << setw(8) << "Units" << setw(20) << "Instructor" <<  setw(10)  << "Seats" << setw(10) << "Waitlist" << setw(10) <<  "Waitlist" << endl;

    cout << left << setw(6) << "-----" << setw(10) << "-------" << setw(10) << "------" << setw(10)  << "--------" <<  setw(40) <<  "-------------------------------------" << setw(10) << "---------" << setw(10) << "-----" << setw(20) <<  "-------------------" << setw(10) << "-------" << setw(8) << "------" << setw(8) << "------" << setw(20) << "---------------" <<  setw(10)  << "--------" << setw(10) << "--------" << setw(10) <<  "--------" << endl;

}

void Class::print()
{
    cout << left << setw(6) << crn << setw(10) << subject << setw(10) << course << setw(10)  << section <<  setw(40) <<  title << setw(10) << status << setw(10) << days << setw(20) <<  time << setw(10) << room << setw(8) << campus << setw(8) << units << setw(20) << instructor <<  setw(10)  << seats_available << setw(10) << waiting_available << setw(10) <<  waiting_capacity << endl;
}
