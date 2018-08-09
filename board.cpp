
#include <iostream>
#include "board.h"
using namespace std;

void Board::printMat() {
    // upper frame
    cout << " |";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << i + 1 << " |";
    }
    cout << endl;

    // the core
    for (int i = 0; i < SIZE; i++) {
        // between rows
        for (int k = 0; k < SIZE + 1; k++) {
            cout << "- - ";
        }
        cout << endl;

        // the rows
        cout << i + 1 << "|";
        for (int j = 0; j < SIZE; j++) {
            // case black
            if (this->mat[i][j].getColor() == Black) {
                cout << " X |";
            }
            // case white
            else if (this->mat[i][j].getColor() == White) {
                cout << " O |";
            }
            // case empty
            else if (this->mat[i][j].getColor() == None) {
                cout << "   |";
            }
        }
        cout << endl;
    }

    //lower frame
    for (int k = 0; k < SIZE + 1; k++) {
        cout << "- - ";
    }
    cout << endl;
}

Board::Board() {
    // init mat with empty cells
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            this->mat[i][j].setColor(None);
        }
    }
    // put 2 O and 2 X in the center
    this->mat[SIZE/2 -1][SIZE/2 -1].setColor(White);
    this->mat[SIZE/2][SIZE/2].setColor(White);
    this->mat[SIZE/2 -1][SIZE/2].setColor(Black);
    this->mat[SIZE/2][SIZE/2 -1].setColor(Black);
}

Row *Board::getMat() {
    return this->mat;
}

Color Board::update(int x, int y, Color color) {
    if (this->mat[x][y].getIsEmpty() && 0 <= x && x <= SIZE && 0 <= y && y <= SIZE) {
        this->mat[x][y].setColor(color);

        updateWest(x, y, color);
        updateEast(x, y, color);
        updateNorth(x, y, color);
        updateSouth(x, y, color);

        updateNorthEast(x, y, color);
        updateNorthWest(x, y, color);
        updateSouthEast(x, y, color);
        updateSouthWest(x, y, color);


        if (color == Black) {
            return White;
        }
        return Black;
    }
    // case illegal input same color
    return color;
}

void Board::updateWest(int r, int c, Color color) {
    int temp = c;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[r][--c].getColor() == opponent) {
    }

    if (c < 0 || this->mat[r][c].getColor() != color) {
        return;
    }

    c = temp;
    while (this->mat[r][--c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateEast(int r, int c, Color color) {
    int temp = c;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[r][++c].getColor() == opponent) {
    }

    if (c >= SIZE || this->mat[r][c].getColor() != color) {
        return;
    }

    c = temp;
    while (this->mat[r][++c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateNorth(int r, int c, Color color) {
    int temp = r;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[--r][c].getColor() == opponent) {
    }

    if (r < 0 || this->mat[r][c].getColor() != color) {
        return;
    }

    r = temp;
    while (this->mat[--r][c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateSouth(int r, int c, Color color) {
    int temp = r;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[++r][c].getColor() == opponent) {
    }

    if (r >= SIZE || this->mat[r][c].getColor() != color) {
        return;
    }

    r = temp;
    while (this->mat[++r][c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateNorthWest(int r, int c, Color color) {
    int tempR = r;
    int tempC = c;

    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[--r][--c].getColor() == opponent) {
    }

    if (r < 0 || c < 0 || this->mat[r][c].getColor() != color) {
        return;
    }

    r = tempR;
    c = tempC;
    while (this->mat[--r][--c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateNorthEast(int r, int c, Color color) {
    int tempR = r;
    int tempC = c;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[--r][++c].getColor() == opponent) {
    }

    if (r < 0 || c >= SIZE || this->mat[r][c].getColor() != color) {
        return;
    }

    r = tempR;
    c = tempC;
    while (this->mat[--r][++c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateSouthWest(int r, int c, Color color) {
    int tempR = r;
    int tempC = c;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[++r][--c].getColor() == opponent) {
    }

    if (r >= SIZE || c < 0 || this->mat[r][c].getColor() != color) {
        return;
    }

    r = tempR;
    c = tempC;
    while (this->mat[++r][--c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

void Board::updateSouthEast(int r, int c, Color color) {
    int tempR = r;
    int tempC = c;
    Color opponent = Black;
    if (color == Black) {
        opponent = White;
    }

    while (this->mat[++r][++c].getColor() == opponent) {
    }

    if (r >= SIZE || c >= SIZE || this->mat[r][c].getColor() != color) {
        return;
    }

    r = tempR;
    c = tempC;
    while (this->mat[++r][++c].getColor() == opponent) {
        this->mat[r][c].setColor(color);
    }
}

bool Board::isFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (this->mat[i][j].getIsEmpty()) {
                return false;
            }
        }
    }

    return true;
}
