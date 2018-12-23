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
int Board::move(int direction) {
    //TODO collide tiles in direction
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            if(tiles[r][c] == NULL) continue;
            tiles[r][c]->increase();
            score += tiles[r][c]->get_value();
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
void Board::draw_tile() {
}