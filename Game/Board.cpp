#include "Board.h"

void Board::setMines(int level) {
    srand(time(NULL));
    int i;
    int j;
    int cpt;
    if(level) {
        // 10
        cpt = 10;
    } else if(level == 2) {
        // 40
        cpt = 40;
    } else if(level == 3) {
        // 99
        cpt = 99;
    }
    while(cpt > 0) {
        i = rand() % this->COL;
        j = rand() % this->ROW;
        while(this->board[i][j] == 'X') {
            i = rand() % this->COL;
            j = rand() % this->ROW;
        }
        this->board[i][j] = 'X';
        cpt--;
    }
}

void Board::setBoard() {
    for(int i = 0; i < this->ROW; i++) {
        for(int j = 0; j < this->COL; j++) {
            this->board[i][j] = ' ';
        }
    }
}

void Board::setNumbers() {
    // TODO
}

void Board::levelBeginner() {
    // 9 X 9 grid and 10 mines
    this->COL = 9;
    this->ROW = 9;
    this->board = (char**)malloc(this->COL * (sizeof(char*)));
    this->display = (int**)malloc(this->COL * (sizeof(int*)));
    for(int i = 0; i < this->ROW; i++) {
        this->board[i] = (char*)malloc(this->ROW * sizeof(char));
        this->display[i] = (int*)malloc(this->ROW * sizeof(int));
    }
    setBoard();
}

void Board::levelIntermediate() {
    // 16 X 16 grid and 40 mines
    this->COL = 16;
    this->ROW = 16;
    this->board = (char**)malloc(this->COL * (sizeof(char*)));
    this->display = (int**)malloc(this->COL * (sizeof(int*)));
    for(int i = 0; i < this->ROW; i++) {
        this->board[i] = (char*)malloc(this->ROW * sizeof(char));
        this->display[i] = (int*)malloc(this->ROW * sizeof(int));
    }
    setBoard();
}

void Board::levelExpert() {
    // 30 X 30 grid and 99 mines
    this->COL = 30;
    this->ROW = 30;
    this->board = (char**)malloc(this->COL * (sizeof(char*)));
    this->display = (int**)malloc(this->COL * (sizeof(int*)));
    for(int i = 0; i < this->ROW; i++) {
        this->board[i] = (char*)malloc(this->ROW * sizeof(char));
        this->display[i] = (int*)malloc(this->ROW * sizeof(int));
    }
    setBoard();
}

Board::Board(int level) {
    // This level is bewteen 1 and 3
    switch(level) {
        case 1:
            levelBeginner();
            break;
        case 2:
            levelIntermediate();
            break;
        default:
            levelExpert();
    }
}