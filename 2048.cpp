#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
using namespace std;

class Tile;
class Board;


int main() {
    srand(time(NULL));
    // initialize board with 4 spawned tiles
    Board board(4);
    while(true) { // TODO while game is on
        // TODO take input
        board.draw();
        board.move(Move::UP);
        board.spawn_tile();
        if(board.is_full()) break;
    }
    cout << "Game over! your score:" << board.get_score() << endl;
    return 0;
}







/* * * * * * * * * * * * * * * * *
 * Initialize all tiles to null, then spawn 4 tiles
 */


/* * * * * * * * * * * * * * * * *
 * Free board and all tiles
 */
void destroy_board() {
    return;
}
