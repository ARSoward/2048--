#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
using namespace std;

#define ARROW_UP    119
#define ARROW_LEFT  97
#define ARROW_RIGHT 100
#define ARROW_DOWN  115


Move get_move() {
    int c = getchar();
    switch(c) {
        case ARROW_UP:
            return Move::UP;
        case ARROW_DOWN:
            return Move::DOWN;
        case ARROW_LEFT:
            return Move::LEFT;
        case ARROW_RIGHT:
            return Move::RIGHT;
        default:
            return Move::INVALID;
    }
}

int main() {
    srand(time(NULL));
    // initialize board with 4 spawned tiles
    Board board(4, true);
    Move move = Move::INVALID;
    int moved = 0;
    while(true) {
        board.draw();
        do{
            move = get_move();
        } while (move == Move::INVALID);
        
        moved = board.move(move);
        if(board.is_full()) break;
        if(moved) board.spawn_tile();
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
