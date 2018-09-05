//
//  Project 7 : PersonData and CustomerData classes
//  22B_KIM_HOWON_H7C
//
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "PersonData.h"
#include "CustomerData.h"
using namespace std;

// Function Prototype
void welcome();
void displayPersonData(PersonData personList);
void displayCustomerData(CustomerData customerList);
void goodbye();

int main()
{
    welcome();
    
    // Base class object
    PersonData person("Kim","Howon","Lawrence Express Way 813","Cupertino","CA","95014","408-123-4567");
    
    // Derived class object
    CustomerData customer("Lee","Hyejin","Hollenbeck 923","Sunnyvale","CA","95032","669-123-4567",12345,0);
    CustomerData customer2;
    
    // Display the object
    cout << ">>Person #1<<" << endl;
    displayPersonData(person);
    cout << endl << ">>Customer #1<<" << endl;
    displayCustomerData(customer);
    
    // Test the derived class function
    customer2.setFirst("James");
    customer2.setLast("Bean");
    customer2.setAddress("De Anza 1102");
    customer2.setCity("Cupertino");
    customer2.setState("CA");
    customer2.setZip("95014");
    customer2.setPhone("408-9876-5432");
    customer2.setCustomerNumber(54321);
    customer2.setMailingList(1);
    
    
    // Diplay the derived class object
    cout << endl << ">>Customer #2<<" << endl;
    displayCustomerData(customer2);
    
    goodbye();
    
    return 0;
}
//*****************************************************************************
// Definition of function welcome
// This function displays the welcome screen
// Input Parameter : none
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void welcome()
{
    cout << "Welcome to the Inheritance Project" << endl;
    cout << "___________________________________" << endl << endl;
}


//*****************************************************************************
// Definition of function displayPersonData
// This function display the PersonData object's data
// Input Parameter : personList (PersonData object)
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void displayPersonData(PersonData personList)
{
    cout << "First Name : " << personList.getLast() << endl;
    cout << "Last Name : " << personList.getFirst() << endl;
    cout << "Address : " << personList.getAddress() << endl;
    cout << "City : " << personList.getCity() << endl;
    cout << "State : " << personList.getState() << endl;
    cout << "Zip : " << personList.getZip() << endl;
    cout << "Phone : " << personList.getPhone() << endl;
}


//*****************************************************************************
// Definition of function displayCustomerData
// This function display the CustomerData object's data
// Input Parameter : customerList (CustomerData object)
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void displayCustomerData(CustomerData customerList)
{
    cout << "First Name : " << customerList.getLast() << endl;
    cout << "Last Name : " << customerList.getFirst() << endl;
    cout << "Address : " << customerList.getAddress() << endl;
    cout << "City : " << customerList.getCity() << endl;
    cout << "State : " << customerList.getState() << endl;
    cout << "Zip : " << customerList.getZip() << endl;
    cout << "Phone : " << customerList.getPhone() << endl;
    cout << "Customer Number : " << customerList.getCustomerNumber() << endl;
    
    if(customerList.getMailingList()==false)
    {
        cout << "Mailing List : No" << endl;
    }
    else
    {
        cout << "Mailing List : Yes" << endl;
    }
}

//*****************************************************************************
// Definition of function goodbye
// This function displays the goodbye screen
// Input Parameter : none
// Output Parameter : none
// Return Value : none
//*****************************************************************************

void goodbye()
{
    cout << endl << endl << "______________________________________________" << endl << endl;
    cout << "Thank you for using the Inheritance Project" << endl;
    cout << "IDE : XCODE 6.3.2 (Mac OS X 10.04)" << endl;
    cout << "Developer : Howon Kim" << endl;
}

/* OUTPUT
 Welcome to the Inheritance Project
 ___________________________________
 
 >>Person #1<<
 First Name : Kim
 Last Name : Howon
 Address : Lawrence Express Way 813
 City : Cupertino
 State : CA
 Zip : 95014
 Phone : 408-123-4567
 
 >>Customer #1<<
 First Name : Lee
 Last Name : Hyejin
 Address : Hollenbeck 923
 City : Sunnyvale
 State : CA
 Zip : 95032
 Phone : 669-123-4567
 Customer Number : 12345
 Mailing List : No
 
 >>Customer #2<<
 First Name : Bean
 Last Name : James
 Address : De Anza 1102
 City : Cupertino
 State : CA
 Zip : 95014
 Phone : 408-9876-5432
 Customer Number : 54321
 Mailing List : Yes
 
 
 ______________________________________________
 
 Thank you for using the Inheritance Project
 IDE : XCODE 6.3.2 (Mac OS X 10.04)
 Developer : Howon Kim
*/