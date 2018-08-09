//
// Created by orifogler on 8/7/18.
//

#include <iostream>
#include "player.h"
using namespace std;

#ifndef ENUM
#define ENUM
enum Color {Black, White, None};
#endif

Player::Player() {
}

string Player::makeMove() {
    char side;

    if (this->color == Black) {
        side = 'X';
    } else if (this->color == White) {
        side = 'O';
    }

    cout << side << ": It's your move." << endl;
    cout << "Please enter your move row,col:" << endl;
    string input;
    cin >> input;

    return input;
}

void Player::setColor(Color color) {
    this->color = color;
}

int Player::score() {
    return 0;
}
