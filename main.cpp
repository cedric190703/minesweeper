#include <iostream>
#include "Game/Game.h"

using namespace std;

int main() {
    // Initialize objects
    Player* player = new Player("name");
    int level;
    printf("What is your level (1-3) :\n");
    scanf("%d", &level);
    while(level < 1 || level > 3) {
        printf("Invalid level.\n");
        scanf("%d", &level);
    }
    Board* board = new Board(level);
    Game game(player, board);

    int size = board->getSize();
    int i;
    int j;
    int res;

    while(true) {
        // Draw the board
        game.drawBoard();

        // Get the position of the player
        printf("Give the index position for the x axis :\n");
        scanf("%d", &i);
        while(i < 0 || i >= size) {
            printf("Give a correct index position for the x axis :\n");
            scanf("%d", &i);
        }
        printf("Give the index position for the y axis :\n");
        scanf("%d", &j);
        while(j < 0 || j >= size) {
            printf("Give a correct index position for the y axis :\n");
            scanf("%d", &j);
        }
        // Check changements
        res = game.checkChanges(i, j);

        if(res == 2) {
            continue;
        } else {
            break;
        }
        // Draw the board
        game.drawBoard();
    }
    printf("\n");
    // Display the result
    if(res) {
        printf("You just won this game.\n");
        game.drawBoard();
    } else {
        printf("\033[31mYou lose this game.\033[0m\n");
        game.lost();
    }

    return 0;
}