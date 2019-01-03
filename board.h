#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
/* * * * * * * * * * * * * * * * *
 * Board object has a 4x4 array of pointers to Tile objects.
 * New tiles are added to the board with spawn_tile(), and the tiles 
 * can be combined using move().
 */
enum class Move {UP, DOWN, LEFT, RIGHT, INVALID};
class Board {
    public:
        Board(int tile_count, bool debug);
        ~Board();
        int move(Move direction);
        Tile* spawn_tile();
        void draw();
        int get_score();
        bool is_full();
    private:
        Tile* tiles[4][4];
        int score;
        Tile** find_space(void);
        int move_tile(int row, int col, int row_shift, int col_shift);
        void clear();
        void draw_top();
        void draw_row();
        void draw_boundary();
        void draw_bottom();
};
#endif