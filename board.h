
#ifndef REVERSI100_BOARD_H
#define REVERSI100_BOARD_H

#include "cell.h"

const int SIZE = 8;
typedef Cell Row[SIZE];

class Board {
private:
    Cell mat[SIZE][SIZE];
public:
    Board();
    void printMat();
    Row *getMat();
    Color update(int x, int y, Color color);
    bool isFull();
    void updateWest(int x, int y, Color color);
    void updateEast(int x, int y, Color color);
    void updateNorth(int x, int y, Color color);
    void updateSouth(int x, int y, Color color);
    void updateNorthWest(int x, int y, Color color);
    void updateNorthEast(int x, int y, Color color);
    void updateSouthWest(int x, int y, Color color);
    void updateSouthEast(int x, int y, Color color);

};


#endif //REVERSI100_BOARD_H
