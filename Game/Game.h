#pragma once
#include "Player.h"
#include "Board.h"

class Game {
private:
    Player* player;
    Board* board;
public:
    Game(Player* player, Board* board) : player(player), board(board) {};
    ~Game() {
        delete this->board;
        delete this->player;
    }
    Player* getPlayer() {  return this->player; };
    Board* getBoard() { return this->board; };
    void drawBoard();
    int checkChanges();
};