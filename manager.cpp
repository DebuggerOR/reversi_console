
#include "manager.h"

Manager::Manager() {
    string move;

    this->blackPlayer.setColor(Black);
    this->whitePlayer.setColor(White);

    Color curTurn = Black;

    do {
        this->board.printMat();

        // black turn
        if (curTurn == Black) {
            move = this->blackPlayer.makeMove();
            // white turn
        } else {
            move = this->whitePlayer.makeMove();
        }

        // 48 to convert from ascii, 1 because start in 0
        curTurn = this->board.update(move[0] - 48 - 1, move[2] - 48 - 1, curTurn);
    } while (!this->board.isFull());

    char winner = 'X';
    if (whitePlayer.score() > blackPlayer.score()) {
        winner = 'O';
    }

    cout << "the winner is: " << winner << endl;
}
