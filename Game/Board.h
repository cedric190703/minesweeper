#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Board {
private:
    char** board;
    int** display;
    int COL;
    int ROW;
    int level; // 1-3 -> Beginner-Expert
public:
    // X -> Mines
    // O -> Hidden cell
    Board(int level);
    Board(Board &boardCpy) {
        this->board = boardCpy.board;
        this->COL = boardCpy.COL;
        this->ROW = boardCpy.ROW;
        this->display = boardCpy.display;
        if(boardCpy.level > 0 && boardCpy.level < 3) {
            this->level = boardCpy.level;
        }
    };
    ~Board() {
        for (int i = 0; i < this->ROW; i++) {
            free(this->board[i]);
            free(this->display[i]);
        }

        free(this->board);
        free(this->display);
    };
    void levelBeginner();
    void levelIntermediate();
    void levelExpert();
    void setMines(int level);
    void setBoard();
    void setNumbers();
    int getSize() { return this->COL; };
};