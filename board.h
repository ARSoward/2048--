#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
/* * * * * * * * * * * * * * * * *
 * Board object has a 4x4 array of pointers to Tile objects.
 * New tiles are added to the board with spawn_tile(), and the tiles 
 * can be combined using move().
 */
class Board {
    public:
        Board(int tile_count);
        ~Board();
        int move(int direction);
        Tile* spawn_tile();
        void draw();
        int get_score();
        bool is_full();
    private:
        Tile* tiles[4][4];
        int score;
        bool full;
        Tile** find_space(void);
        void clear();
        void draw_top();
        void draw_row();
        void draw_boundary();
        void draw_bottom();
        void draw_tile();
};
#endif