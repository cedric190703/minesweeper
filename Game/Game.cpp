#include "Game.h"

void Game::drawBoard() {
    board->drawBoard();
}

int Game::checkChanges(int i, int j) {
    if(board->getCell(i, j) == 'X') {
        return 0;
    }

    // Get away spaces -> boucle
    board->updateBoard(i, j);

    // Check for a win
    if(board->finish()) {
        return 1;
    }
    return 2;
}
