#include <iostream>
#include <iomanip>
#include "tile.h"
using namespace std;

Tile::Tile(int v) {
    value = v;
    color = 0x000;
}

/* * * * * * * * * * * * * * * * *
 * Draw my value in my color, left-justified.
 */
void Tile::draw() {
    cout << left;
    cout << "| " << setw(6) << value << "|";
    // TODO draw using hex color
}

/* * * * * * * * * * * * * * * * *
 * Double value and update color accordingly
 */
void Tile::increase() {
    value = value << 1;
    //TODO change color
}

int Tile::get_value() {
    return value;
}