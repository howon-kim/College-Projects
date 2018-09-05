//
//  Project : Game of 21
//  22B_KIM_HOWON_H5
//
//  Created by HOWON KIM
//  IDE : Xcode 6.3.2 (MAC OS X 10.04)
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Die.h"
#include "Player.h"
using namespace std;

const int MAX_PLAYER = 5; // Maximum people for play

// FUNCTION PROTOTYPE
void welcome();
void diceStage(Player *dcePlayer, Die dceDie, int dceIndex);

void makeUserName(Player *munPlayer, int munIndex);
void rollDice(Player *rdPlayer, Die rdDie, int rdIndex);

void displayScore(Player *dsPlayer, int dsIndex);
void saveResult(Player *svPlayer, int svIndex);
void displayResult(Player *dpPlayer, int dpIndex);

void saveResultToFile(Player *srtfPlayer, int srtfIndex);

void goodbye();

// MAIN FUNCTION
int main()
{
    int index = 0; // Trace the number of player

    Player *player = new Player[MAX_PLAYER]; // Array of the Player object
    Die die; // object of Die
    
    welcome();

    char select = 'y';
    
    // GAME PROCESS START
    while(select == 'y' && index < MAX_PLAYER)
    {

        if(select == 'y')
        {
            makeUserName(player, index); // Make user name
            diceStage(player, die, index); // Play the game
            saveResult(player, index); // Save the result
            displayResult(player, index); // Display the result
            cout << "Do you want to play the game again? (y/n) : ";
            cin >> select;
            

            while(select != 'y' && select != 'n') // Input validation
            {
                cout << "Incorrect Choice. Do you want to play the game again? (y/n) : ";
                cin >> select;
            }
            cin.ignore();
        }
        
        if(select == 'n') // If user want to stop the game
        {
            cout << "Finish the game" << endl;
        }
        
        index++; // Increase the current number of players
      
        if(index == MAX_PLAYER) // If number of user is exceed maximum number of user, finish the program
        {
            select = 'n';
            cout << "Exceed the number of maximum player" << endl;
            cout << "Finish the program" << endl;
        }
       
        
    }
    saveResultToFile(player, index); // Save the result to the file
    
    delete [] player;

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
    cout << "######################################################" << endl
         << " WELCOME TO THE GAME OF 21" << endl
         << "######################################################" << endl << endl;
}


//*****************************************************************************
// Definition of function diceStage
// This function plays the game
// Input Parameter
// - dceDie : Object of the Die. For roll the dice and calculate the total number
// - dceIndex : Access the current number of player
// Output Parameter
// - dcePlayer : Object of the Player. For access the player's name, score
// Return Value : none
//*****************************************************************************
void diceStage(Player *dcePlayer, Die dceDie, int dceIndex)
{
    char choice = 'y';
    
    while (choice!='n')
    {
        if(choice == 'y')
        {
            rollDice(dcePlayer, dceDie, dceIndex); // Roll the dice
            displayScore(dcePlayer, dceIndex); // Display the score
            cout << " Do you want to continue the game? (y/n) : ";
            cin >> choice;
            
            while(choice != 'y' && choice != 'n') // Input validation
            {
                cout << " Incorrect Choice. Do you want to continue the game? (y/n) : ";
                cin >> choice;
            }
            cin.ignore();
        }
        
        if(choice == 'n') // Finish screen
        {
            cout << " Finish to roll the dice" << endl;
        }
    }
}

//*****************************************************************************
// Definition of function makeUserName
// This function save the user name
// Input Parameter
// - munIndex : Access the current number of player
// Output Parameter
// - munPlayer : Object of the Player. For access the player's name
// Return Value : none
//*****************************************************************************

void makeUserName(Player *munPlayer, int munIndex)
{
    string userName = "";
    cout << " * Enter the User Name : " ;
    getline(cin, userName);
    cout << endl;
    munPlayer[munIndex].setPlayer(userName);
}



//*****************************************************************************
// Definition of function rollDice
// This function save the user name
// Input Parameter
// - rdIndex : Access the current number of player
// - rdDie : Object of the Die. For roll the dice and calculate the total number
// Output Parameter
// - rdPlayer : Object of the Player. For access the player's score
// Return Value : none
//*****************************************************************************

void rollDice(Player *rdPlayer, Die rdDie, int rdIndex)
{
    int computer = 0;
    int user = 0;

    rdDie.roll();
    computer = rdDie.calTotal();
    rdPlayer[rdIndex].setComScore(computer);
    
    cout << " **************************" << endl
         << " * Enter to roll the Dice *" << endl
         << " **************************";
    cin.get();
    
    rdDie.roll();
    user = rdDie.calTotal();
    rdPlayer[rdIndex].setUserScore(user);
    

}


//*****************************************************************************
// Definition of function displayScore
// This function displays the score
// Input Parameter
// - dsIndex : Access the current number of player
// Output Parameter
// - dsPlayer : Object of the Player. For access the player's name, score
// Return Value : none
//*****************************************************************************

void displayScore(Player *dsPlayer, int dsIndex)
{
    cout << " " << left << setw(10) << "Computer" << setw(5) << "VS" << setw(10) << dsPlayer[dsIndex].getPlayer() << endl;
    cout << " " << right << setw(8) << dsPlayer[dsIndex].getComScore() << setw(7) << " " << left << setw(4) << dsPlayer[dsIndex].getUserScore() << endl;
    cout << " **************************" << endl << endl;
}


//*****************************************************************************
// Definition of function saveResult
// This function save the result of the game
// Input Parameter
// - svIndex : Access the current number of player
// Output Parameter
// - svPlayer : Object of the Player. For access the player's result
// Return Value : none
//*****************************************************************************

void saveResult(Player *svPlayer, int svIndex)
{
    int computer = svPlayer[svIndex].getComScore();
    int user = svPlayer[svIndex].getUserScore();
    if(user <= 21)
    {
        if(user > computer)
        {
        svPlayer[svIndex].setResult("WIN");
        }
        
        else if(user < computer)
        {
            svPlayer[svIndex].setResult("LOSE");
        }
        
        else
        {
            svPlayer[svIndex].setResult("DRAW");
        }
        
    }
    else if(user > 21)
    {
        svPlayer[svIndex].setResult("LOSE");

    }

}


//*****************************************************************************
// Definition of function displayResult
// This function displays the final result
// Input Parameter
// - dpIndex : Access the current number of player
// Output Parameter
// - dpPlayer : Object of the Player. For access the player's name, score
// Return Value : none
//*****************************************************************************

void displayResult(Player *dpPlayer, int dpIndex)
{
    cout << endl << " FINAL RESULT" << endl;
    cout << "****************************" << endl;
    cout << "* " << left << setw(10) << "Computer" << setw(5) << "VS" << setw(10) << dpPlayer[dpIndex].getPlayer() << "*" << endl;
    cout << "* " << right << setw(8) << dpPlayer[dpIndex].getComScore() << setw(7) << " " << left << setw(10) << dpPlayer[dpIndex].getUserScore() << "*" << endl;
    cout << left << setw(10) << "* Result : " << setw(15) << dpPlayer[dpIndex].getResult() << " *" << endl;
    cout << "****************************" << endl << endl;
}

//*****************************************************************************
// Definition of function saveResultToFile
// This function saves every player's score and result and name
// Input Parameter
// - srtfIndex : Access the total number of player
// Output Parameter
// - srtfPlayer : Object of the Player. For access the player's name, score, result
// Return Value : none
//*****************************************************************************

void saveResultToFile(Player *srtfPlayer, int srtfIndex)
{
    ofstream outfile;
    outfile.open("/Users/HWKIM/Desktop/22B_KIM_HOWON_H5/22B_KIM_HOWON_H5/players.txt");
    
    if(!outfile)
    {
        cout << "INCORRECT FILE PATH. EXIT THE PROGRAM" << endl;
        exit(111);
    }
    
    outfile << left << setw(20) << "USER NAME" << setw(20) << "COMPUTER SCORE" << setw(20) << "USER SCORE" << setw(20) << "RESULT" << endl;
    for(int i=0; i<srtfIndex; i++)
    {
    outfile << left << setw(20) << srtfPlayer[i].getPlayer() << setw(20) << srtfPlayer[i].getComScore() << setw(20) << srtfPlayer[i].getUserScore() << setw(20) <<srtfPlayer[i].getResult() << endl;
    }
    
    outfile.close();
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
    cout << endl << "######################################################" << endl
         << " THANK YOU FOR USING THE PROGRAM" << endl
         << "######################################################" << endl << endl;
}

/*
 OUTPUT
 ######################################################
 WELCOME TO THE GAME OF 21
 ######################################################
 
 * Enter the User Name : NAME A
 
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME A
 6       8
 **************************
 
 Do you want to continue the game? (y/n) : n
 Finish to roll the dice
 
 FINAL RESULT
 ****************************
 * Computer  VS   NAME A    *
 *        6       8         *
 * Result : WIN             *
 ****************************
 
 Do you want to play the game again? (y/n) : y
 * Enter the User Name : NAME B
 
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME B
 5       7
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME B
 13       17
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME B
 19       23
 **************************
 
 Do you want to continue the game? (y/n) : n
 Finish to roll the dice
 
 FINAL RESULT
 ****************************
 * Computer  VS   NAME B    *
 *       19       23        *
 * Result : LOSE            *
 ****************************
 
 Do you want to play the game again? (y/n) : y
 * Enter the User Name : NAME C
 
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME C
 5       7
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME C
 11       15
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME C
 15       21
 **************************
 
 Do you want to continue the game? (y/n) : n
 Finish to roll the dice
 
 FINAL RESULT
 ****************************
 * Computer  VS   NAME C    *
 *       15       21        *
 * Result : WIN             *
 ****************************
 
 Do you want to play the game again? (y/n) : y
 * Enter the User Name : NAME D
 
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME D
 9       7
 **************************
 
 Do you want to continue the game? (y/n) : n
 Finish to roll the dice
 
 FINAL RESULT
 ****************************
 * Computer  VS   NAME D    *
 *        9       7         *
 * Result : LOSE            *
 ****************************
 
 Do you want to play the game again? (y/n) : y
 * Enter the User Name : NAME E
 
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME E
 4       5
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME E
 13       16
 **************************
 
 Do you want to continue the game? (y/n) : y
 **************************
 * Enter to roll the Dice *
 **************************
 Computer  VS   NAME E
 20       23
 **************************
 
 Do you want to continue the game? (y/n) : n
 Finish to roll the dice
 
 FINAL RESULT
 ****************************
 * Computer  VS   NAME E    *
 *       20       23        *
 * Result : LOSE            *
 ****************************
 
 Do you want to play the game again? (y/n) : y
 Exceed the number of maximum player
 Finish the program
*/