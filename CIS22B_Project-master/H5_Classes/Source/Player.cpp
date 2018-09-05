//
//  Player.cpp
//  22B_KIM_HOWON_H5
//
//  Created by HOWON KIM on 6/2/15.
//  Copyright (c) 2015 HOWON KIM. All rights reserved.
//
//  Implementation file for the Player Class
//  Player Class hold the name of player and user, opponent's score and result of the game
//  Player Class have the function that receives the value of player's name, opponent/user's score and result of the game
//  Player Class also have the function that returns the value of player's name, opponen/user's score and result of the game

#include "Player.h"
#include <iostream>
using namespace std;

//********************************************************************
// The setPlayer member function set the name of player
//********************************************************************

void Player::setPlayer(string user)
{
    player = user;
}

//********************************************************************
// The setUserScore member function add the score of player
//********************************************************************

void Player::setUserScore(int uscore)
{
    userScore += uscore;
}

//********************************************************************
// The setComScore member function add the score of opponent
//********************************************************************

void Player::setComScore(int cscore)
{
    comScore += cscore;
}

//********************************************************************
// The setComScore member function set the result of game
//********************************************************************

void Player::setResult(string winlose)
{
    result = winlose;
}