#include <iostream>
#include <iomanip>
#include "board.h"
#include "tile.h"
using namespace std;

Board::Board(int tile_count) {
    score = 0;
    full = 0;
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            tiles[r][c] = NULL;
        }
    }
    for(int i=0; i<tile_count; i++) {
        spawn_tile();
    }
}

Board::~Board() {
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            if(tiles[r][c] == NULL) continue;
            delete tiles[r][c];
        }
    }
}

/* * * * * * * * * * * * * * * * *
 * Move takes a direction and moves all tiles on the board in that direction.
 * If two colliding tiles are of the same value, combine them.
 */
int Board::move(Move direction) {
    //TODO collide tiles in direction
    int rshift = 0;
    int cshift = 0;
    switch(direction) {
        case Move::UP:
            rshift = -1;
            break;
        case Move::DOWN:
            rshift = 1;
            break;
        case Move::LEFT:
            cshift = -1;
            break;
        case Move::RIGHT:
            cshift = 1;
            break;
        default:
            return 1;
    }
    if(direction == Move::UP || direction == Move::LEFT) {
        for(int r=0; r<4; r++) {
            for(int c=0; c<4; c++) {
                if(tiles[r][c] == NULL) continue;
                move_tile(r, c, rshift, cshift);
            }
        }
    }
    else {
       for(int r=3; r>=0; r--) {
            for(int c=3; c>=0; c--) {
                if(tiles[r][c] == NULL) continue;
                move_tile(r, c, rshift, cshift);
            }
        } 
    }

    return 0;
}

/* * * * * * * * * * * * * * * * *
 * Spawn tile selects a random spot on the board and iterates through until
 * it finds an unoccupied space. If it doesn't find an empty space, raise error.
 */
Tile* Board::spawn_tile() {
    int val = rand()%2+1;
    Tile** space = find_space();
    if(space == NULL) {
        full = true;
        return NULL;
    }
    Tile* newtile = new Tile(val*2);
    *space = newtile; 
    return newtile;
}

/* * * * * * * * * * * * * * * * *
 * Getters
 */
int Board::get_score() {
    return score;
}
bool Board::is_full() {
    return full;
}

/* * * * * * * * * * * * * * * * *
 * Recursively move tile in direction. When we try to move a tile,
 * a collision occurs with the tile already in that space. Then, 
 * there are 4 things that can happen. 
 * base case: collide with the edge
 *      don't move this tile
 *      stop
 * case 0: collide with NULL tile
 *      swap NULL tile and this tile
 *      continue moving this tile from new location
 * case 1: collide with tile of different value
 *      don't move this tile
 *      stop
 * case 2: collide with tile of the same value
 *      delete this tile
 *      increase value of collided tile
 *      continue moving, but with the collided tile
 */
void Board::move_tile(int r, int c, int rshift, int cshift) {
    // BASE CASE: first make sure we can move tile
    if(tiles[r][c] == NULL 
    || r + rshift >= 4 || r + rshift < 0 
    || c + cshift >= 4 || c + cshift < 0) {
        cout << "not moving tile at "<< r << ", " << c << endl;
        return;
    } 
    Tile* this_tile = tiles[r][c];
    Tile* collide_tile = tiles[r+rshift][c+cshift];
    // CASE 0
    if(collide_tile == NULL) {
        tiles[r+rshift][c+cshift] = this_tile;
        tiles[r][c] = NULL;
        return move_tile(r+rshift, c+cshift, rshift, cshift);
    }
    // CASE 1
    if(collide_tile->get_value() != this_tile->get_value()) {
        return;
    }
    // CASE 2
    score += this_tile->get_value();
    this_tile = NULL;
    collide_tile->increase();
    return move_tile(r+rshift, c+cshift, rshift, cshift);
}

/* * * * * * * * * * * * * * * * *
 * Helper function to find empty space on board
 */
Tile** Board::find_space(void) {
    // initial attempt
    int start_r = rand()%4;
    int start_c = rand()%4;
    // iterate through until we find an empty tile
    for(int r=start_r; r<start_r+4; r++) {
        for(int c=start_c; c<start_c+4; c++) {
            if (tiles[r%4][c%4] == NULL) 
                return &tiles[r%4][c%4];
        }
    }
    return NULL;
}

/* * * * * * * * * * * * * * * * *
 * Draw the board
 */
void Board::draw() {
    draw_top();
    for(int r=0; r < 4; r++) {
        draw_row();
        for(int c=0; c < 4; c++) {
            if(tiles[r][c] == NULL) cout << "|       |";
            else tiles[r][c]->draw();
        }
        cout << endl;
        draw_row();
        if(r < 3) draw_boundary();
    }
    draw_bottom();
}

/* * * * * * * * * * * * * * * * *
 * Helper functions to draw board
 */
void Board::clear() {
    cout << "clear sequence";
}
void Board::draw_top() {
    cout << ".-------..-------..-------..-------."  << endl;
}
void Board::draw_row() {
    cout << "|       ||       ||       ||       |"  << endl;
}
void Board::draw_boundary() {
    cout << ":=======++=======++=======++=======:"  << endl;
}
void Board::draw_bottom() {
    cout << "'-------''-------''-------''-------'"  << endl;
}
