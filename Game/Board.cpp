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
            this->display[i][j] = 0;
        }
    }
}

int Board::validCell(int i, int j) {
    return ((i >= 0 && i < this->COL) && (j >= 0 && j < this->COL)) ? 1 : 0;
}

int Board::getMines(int row, int col) {
    int cpt = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (validCell(i, j) && this->board[i][j] == 'X') {
                cpt++;
            }
        }
    }
    return cpt;
}

void Board::setNumbers() {
    int cpt = 0;
    for(int i = 0; i < this->COL; i++) {
        for(int j = 0; j < this->ROW; j++) {
            if(this->board[i][j] == 'X') {
                continue;
            }
            cpt = getMines(i, j);
            if(cpt > 0) {
                this->board[i][j] = '0' + cpt;
            }
        }
    }
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
    setMines(level);
    setNumbers();
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
    setMines(level);
    setNumbers();
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

int Board::finish() {
    for(int i = 0; i < this->COL; i++) {
        for(int j = 0; j < this->ROW; j++) {
            if(this->display[i][j] == 0 && this->board[i][j] != 'X') {
                return 0;
            }
        }
    }
    return 1;
}

void Board::drawBoard() {
    printf("\n");
    for(int x = 0; x < this->COL; x++) {
        printf("+---");
    }
    printf("+\n");
    for(int i = 0; i < this->COL; i++) {
        for(int j = 0; j < this->ROW; j++) {
            if(this->display[i][j]) {
                printf("| %c ", this->board[i][j]);
            } else {
                printf("| O ");
            }
        }
        printf("|\n");
        for(int x = 0; x < this->COL; x++) {
            printf("+---");
        }
        printf("+\n");
    }
    printf("\n");
}

// Recursively call cells from one path and then try to go in the cells
void Board::updateBoard(int i, int j) {
    if (board[i][j] == '*' || this->display[i][j]) {
        return;
    }
    this->display[i][j] = 1;
    if (board[i][j] == ' ') {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = i + dx;
                int ny = j + dy;
                if (validCell(nx, ny)) {
                    updateBoard(nx, ny);
                }
            }
        }
    }
    if(finish()) {
        return;
    }
}

void Board::revealMines() {
    printf("\n");
    for(int x = 0; x < this->COL; x++) {
        printf("+---");
    }
    printf("+\n");
    for(int i = 0; i < this->COL; i++) {
        for(int j = 0; j < this->ROW; j++) {
            if(this->board[i][j] == 'X') {
                printf("| \033[31mX\033[0m ");

            } else {
                printf("| %c ", this->board[i][j]);
            }
        }
        printf("|\n");
        for(int x = 0; x < this->COL; x++) {
            printf("+---");
        }
        printf("+\n");
    }
    printf("\n");
}