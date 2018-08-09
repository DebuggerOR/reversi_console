
#ifndef REVERSI100_CELL_H
#define REVERSI100_CELL_H

#ifndef ENUM
#define ENUM
enum Color {Black, White, None};
#endif

class Cell {
private:
    Color color;
    bool isEmpty;

public:
    Cell();

    void setIsEmpty(bool isEmpty);

    bool getIsEmpty();

    void setColor(Color color);

    char getColor();
};

#endif //REVERSI100_CELL_H
