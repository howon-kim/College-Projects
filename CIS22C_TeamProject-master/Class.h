//
//  Class.h
//  Class
//
//  Created by HOWON KIM on 2/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#ifndef Class_h
#define Class_h
#include <cstddef>
#include <string>
#include <iostream>
#include "BST.h"
#include "HashTable.h"
using namespace std;


class Class {

private:
    
    string crn; // Primary Key
    string subject;
    string course; // Secondly Key
    string section;
    
    
    string title;
    string status;
    string days;
    string time;
    string room;
    string campus;
    double units;
    string instructor;
    int seats_available;
    int waiting_available;
    int waiting_capacity;
    


    

    
public:

    /* Constructor */
    Class():crn(""), subject(""), course(""), section(""), title(""), status(""), days(""), time(""),room(""), campus(""), units(0.0), instructor(""), seats_available(0), waiting_available(0), waiting_capacity(0){};

    Class(string ncrn, string nsubject, string ncourse, string nsection, string ntitle, string nstatus, string ndays, string ntime, string nroom, string ncampus, double nunits, string ninstructor, int nseats_available, int nwaiting_available, int nwaiting_capacity):crn(ncrn), subject(nsubject), course(ncourse), section(nsection), title(ntitle), status(nstatus), days(ndays), time(ntime), room(nroom), campus(ncampus), units(nunits), instructor(ninstructor), seats_available(nseats_available), waiting_available(nwaiting_available), waiting_capacity(nwaiting_capacity){};

    /* Destructor */
    ~Class()
    {
        crn = "";
        subject = "";
        section = "";
        title = "";
        status = "";
        days = "";
        time = "";
        room = "";
        campus = "";
        units = 0.0;
        instructor = "";
        seats_available = 0;
        waiting_available = 0;
        waiting_capacity = 0;
        
    }
    
    
    /* Accessor */
    string getCRN(){return crn;}
    string getSubject(){return subject;}
    string getCourse(){return course;}
    string getSection(){return section;}
    string getTitle(){return title;}
    string getStatus(){return status;}
    string getDays(){return days;}
    string getTime(){return time;}
    string getRoom(){return room;}
    string getCampus(){return campus;}
    double getUnits(){return units;}
    string getInstructor(){return instructor;}
    int getSeats_available(){return seats_available;}
    int getWaiting_available(){return waiting_available;}
    int getWaiting_capacity(){return waiting_capacity;}
    
    
    /* Mutator */
    void setCRN(string ncrn){crn = ncrn;}
    void setSubject(string nsubject){subject = nsubject;}
    void setCourse(string ncourse){course = ncourse;}
    void setSection(string nsection){section = nsection;}
    void setTitle(string ntitle){title = ntitle;}
    void setStatus(string nstatus){status = nstatus;}
    void setDays(string ndays){days = ndays;}
    void setTime(string ntime){time = ntime;}
    void setRoom(string nroom){room = nroom;}
    void setCampus(string ncampus){campus = ncampus;}
    void setUnits(double nunits){units  = nunits;}
    void setInstructor(string ninstructor){instructor = ninstructor;}
    void setSeats_available(int nseats_available){seats_available = nseats_available;}
    void setWaiting_available(int nwaiting_available){waiting_available = nwaiting_available;}
    void setWaiting_capacity(int nwaiting_capacity){waiting_capacity = nwaiting_capacity;}
    

    void print();
    void displayCategory();

};


#endif /* Class_h */
