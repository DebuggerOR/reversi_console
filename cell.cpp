
#include "cell.h"

void Cell::setIsEmpty(bool isEmpty) {
    this->isEmpty = isEmpty;
}

bool Cell::getIsEmpty() {
    return this->isEmpty;
}

void Cell::setColor(Color color) {
    this->color = color;
    if (color != None) {
        this->isEmpty = false;
    }
}

char Cell::getColor() {
    return this->color;
}

Cell::Cell() {
    this->color = None;
    this->isEmpty = true;
}