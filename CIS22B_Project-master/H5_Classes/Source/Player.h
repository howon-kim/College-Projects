//
//  Player.h
//  22B_KIM_HOWON_H5
//
//  Created by HOWON KIM on 6/2/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Specification file for the Player Class
//  Player Class hold the name of player and user, opponent's score and result of the game
//  Player Class have the function that receives the value of player's name, opponent/user's score and result of the game
//  Player Class also have the function that returns the value of player's name, opponen/user's score and result of the game

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <iostream>
using namespace std;
class Player
{
private:
    string player; // Name of player
    int userScore; // User's score
    int comScore; // Opponent's score
    string result; // Result of the game
    
public:
    void setPlayer(string); // Set the name of player to a value
    void setUserScore(int); // Set the user's score to a value
    void setComScore(int); // Set the opponent's score to a value
    void setResult(string); // Set the result of the game to a value
    
    string getPlayer() // Returns the name of player
    {return player;}
    int getUserScore() // Returns the user's score
    {return userScore;}
    int getComScore() // Returns the opponent's score
    {return comScore;}
    string getResult() // Returns the result of the game
    {return result;}

    
    
};


#endif /* defined(PLAYER_H) */
