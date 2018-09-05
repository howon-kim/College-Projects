// KimHowon_final : Final
// KimHowon_final.cpp
//
// Environment : Windows 7 (Visual Studio 2013)
// Made by Howon Kim at Mar.26.2015

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function Prototype
void showMenu(void);
int addItem(long int[], string[], int[], double[], double[], const int);
void updateItem(const long int[], const string[], int[], double[], double[], const int);
int searchList(const long int[], const int, int);
void retrieveItem(const long int[], const string[], const int[], const double[], const double[], const int);
void listItem(const long int[], const string[], const int[], const double[], const double[], const int);


// Main function
int main()
{
	const int SIZE = 2; // SIZE OF ARRAY
	long int itemNum[SIZE] = { 0 }; //an array of long integers to hold the product numbers
	string itemName[SIZE] = { "" }; //an array of string to hold the product names
	int quantity[SIZE] = { 0 }; //an array of integers to hold each product's quantity
	double unitPrice[SIZE] = { 0.0 }; //an array of double to hold each product's unit price
	double totalPrice[SIZE] = { 0.0 }; //an array of double to hold each product's total price (unit price x quantity)
	int choose = 0; // Choose the menu
	int items = 0; // Number of items

	showMenu(); // Display the menu function
	cin >> choose; // Select the menu
	cout << endl;

	// INPUT VALIDATION
	while (choose<1 || choose>5)
	{
		cout << "Accept only value between 1 and 5 for the menu choice" << endl
			<< "Enter your choice: ";
		cin >> choose;
	}

	// Go to Menu
	while (1)
	{
		switch (choose)
		{
			// Call additem function 
		case 1: items = addItem(itemNum, itemName, quantity, unitPrice, totalPrice, SIZE);
			showMenu(); // Display the menu function
			cin >> choose; // Select the menu
			cout << endl;

			// INPUT VALIDATION
			while (choose<1 || choose>5)
			{
				cout << "Accept only value between 1 and 5 for the menu choice" << endl
					<< "Enter your choice: ";
				cin >> choose;
			}
			break;

		case 2: updateItem(itemNum, itemName, quantity, unitPrice, totalPrice, items);
			showMenu(); // Display the menu function
			cin >> choose; // Select the menu
			cout << endl;

			// INPUT VALIDATION
			while (choose<1 || choose>5)
			{
				cout << "Accept only value between 1 and 5 for the menu choice" << endl
					<< "Enter your choice: ";
				cin >> choose;
			}
			break;

		case 3: retrieveItem(itemNum, itemName, quantity, unitPrice, totalPrice, items);
			showMenu(); // Display the menu function
			cin >> choose; // Select the menu
			cout << endl;

			// INPUT VALIDATION
			while (choose<1 || choose>5)
			{
				cout << "Accept only value between 1 and 5 for the menu choice" << endl
					<< "Enter your choice: ";
				cin >> choose;
			}
			break;

		case 4: listItem(itemNum, itemName, quantity, unitPrice, totalPrice, items);
			showMenu(); // Display the menu function
			cin >> choose; // Select the menu
			cout << endl;

			// INPUT VALIDATION
			while (choose<1 || choose>5)
			{
				cout << "Accept only value between 1 and 5 for the menu choice" << endl
					<< "Enter your choice: ";
				cin >> choose;
			}
			break;

		case 5:
			return 0;
			break;
		} // END SWITCH
	}
}

// Display the memu above
void showMenu(void)
{
	cout << "=====================================================" << endl << endl
		<< "		List of Items" << endl << endl
		<< "1. Add Item" << endl
		<< "2. Update Item" << endl
		<< "3. Retrieve Item" << endl
		<< "4. List all" << endl
		<< "5. Quit the Program" << endl << endl
		<< "Enter your choice: ";
	return;
}

//	Add Item Function
int addItem(long int fitemNum[], string fitemName[], int fquantity[], double funitPrice[], double ftotalPrice[], const int SIZE)
{
	int fitems = 0;
	char select = 'y';

	cout << "Enter the requested information for each Item." << endl << endl;
	while ((select == 'y' || select == 'Y') && fitems<SIZE)
	{
		cout << "Enter Item #: ";
		cin >> fitemNum[fitems];
		cout << "Enter name: ";
		cin.ignore();//!!!!!!!! CIN,IGNORE : REMOVED THE ENTER SEQUENCE BY CIN.IGNORE
		//!!!!!!!!!! IMPORTANT !!!!!!!!!! cin >> fitemName[fitems];
		getline(cin, fitemName[fitems]);

		cout << "Enter quantity: ";
		cin >> fquantity[fitems];
		// INPUT VALIDATION
		while (fquantity[fitems] < 0)
		{
			cout << "The quantity must be positive" << endl
				<< "Enter quantity: ";
			cin >> fquantity[fitems];
		}
		cout << "Enter unit price: $";
		cin >> funitPrice[fitems];
		// INPUT VALIDATION
		while (funitPrice[fitems] < 0.10)
		{
			cout << "The unit price must be at least 0.10" << endl
				<< "Enter unit price: $";
			cin >> funitPrice[fitems];
		}
		cout << "Do you want to add more (Y or y): ";
		cin >> select;

		// CALCULATE TOTAL PRICE
		ftotalPrice[fitems] = fquantity[fitems] * funitPrice[fitems];
		// Increase array number
		fitems++;

	}

	return fitems;
}

// SEARCH LIST FUNCTION
int searchList(const long int sitemNum[], const int items, const int fnum_product)
{
	int index = 0;       // Used as a subscript to search array
	int position = -1;   // To record position of search value
	bool found = false;  // Flag to indicate if the value was found

	while (index < items && !found)
	{
		if (sitemNum[index] == fnum_product)  // If the value is found
		{
			found = true;           // Set the flag
			position = index;       // Record the value's subscript
		}
		index++;                   // Go to the next element
	}
	return position;              // Return the position, or -1
}

// UPDATE ITEM FUNCTION
void updateItem(const long int ffitemNum[], const string ffitemName[], int ffquantity[], double ffunitPrice[], double fftotalPrice[], const int items)
{
	long num_product = 0;
	long result = 0;
	cout << "Enter the Item #: ";
	cin >> num_product;
	result = searchList(ffitemNum, items, num_product);
	while (result == -1)
	{
		cout << "-------------------------" << endl << endl
			<< "You look for item #" << num_product << "." << endl
			<< "Sorry we cannot find the Item. Please try again" << endl
			<< "Enter the Item #: ";
		cin >> num_product;
		result = searchList(ffitemNum, items, num_product);
	}
	cout << "Please provide the new data for: " << endl
		<< "Item #" << ffitemNum[result] << endl
		<< "Name: " << ffitemName[result] << endl << endl
		<< "Enter new quantity: ";
	cin >> ffquantity[result];

	// INPUT VALIDATION
	while (ffquantity[result] < 0)
	{
		cout << "The quantity must be positive" << endl
			<< "Enter quantity: ";
		cin >> ffquantity[result];
	}

	cout << "Enter the new price: $";
	cin >> ffunitPrice[result];


	// INPUT VALIDATION
	while (ffunitPrice[result] < 0.10)
	{
		cout << "The unit price must be at least 0.10"
			<< "Enter unit price: $";
		cin >> ffunitPrice[result];
	}
	// CALCULATE TOTAL PRICE
	fftotalPrice[result] = ffquantity[result] * ffunitPrice[result];


	return;
}

void retrieveItem(const long int fffitemNum[], const string fffitemName[], const int fffquantity[], const double fffunitPrice[], const double ffftotalPrice[], const int items)
{
	long num_product = 0;
	long result = 0;
	cout << "Enter the Item #: ";
	cin >> num_product;
	result = searchList(fffitemNum, items, num_product);
	while (result == -1)
	{
		cout << "-------------------------" << endl << endl
			<< "You look for item #" << num_product << "." << endl
			<< "Sorry we cannot find the Item. Please try again" << endl
			<< "Enter the Item #: ";
		cin >> num_product;
		result = searchList(fffitemNum, items, num_product);
	}
	cout << "-----------------------------" << endl
		<< "Retrieve Item information" << endl
		<< "-----------------------------" << endl << endl;
	cout << "Item #" << fffitemNum[result] << endl
		<< setw(10) << left << "Name:" << setw(10) << fffitemName[result] << endl
		<< setw(10) << "Quantity:" << setw(10) << fffquantity[result] << endl
		<< "Unit price:   $ " << setw(10) << fffunitPrice[result] << endl
		<< "Total price:  $ " << setw(10) << ffftotalPrice[result] << endl << endl;
	return;
}

void listItem(const long int ffffitemNum[], const string ffffitemName[], const int ffffquantity[], const double ffffunitPrice[], const double fffftotalPrice[], const int items)
{
	cout << "-------------------------" << endl
		<< "List of all the Items" << endl
		<< "--------------------------" << endl << endl;

	for (int index = 0; index < items; index++)
	{
		cout << "Item #" << ffffitemNum[index] << endl
			<< setw(10) << left << "Name:" << ffffitemName[index] << endl
			<< setw(10) << "Quantity:" << ffffquantity[index] << endl
			<< "Unit price:   $ " << setw(10) << ffffunitPrice[index] << endl
			<< "Total price:  $ " << setw(10) << fffftotalPrice[index] << endl << endl << endl;
	}

	return;

}