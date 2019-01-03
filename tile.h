#ifndef TILE_H
#define TILE_H
/* * * * * * * * * * * * * * * * *
 * Tile simply has an object or a color. It is able to draw its value
 * in its color. The value can be doubles using increase() which will
 * update the color accordingly.
 */
class Tile {
    private:
        char* color; //escape sequence
        int value; //power of two
        void set_color();
    public:
        Tile(int v);
        void draw();
        void increase();
        int get_value();
};
#endif