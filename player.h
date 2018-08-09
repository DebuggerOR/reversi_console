
#ifndef REVERSI100_PLAYER_H
#define REVERSI100_PLAYER_H

#include <iostream>
using namespace std;

#ifndef ENUM
#define ENUM
enum Color {Black, White, None};
#endif

class Player {
    Color color;

public:
    Player();

    string makeMove();

    void setColor(Color color);

    int score();
};


#endif //REVERSI100_PLAYER_H
