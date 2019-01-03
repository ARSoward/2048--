#include <iostream>
#include <iomanip>
#include "tile.h"
using namespace std;

Tile::Tile(int v) {
    value = v;
    set_color();
}

/* * * * * * * * * * * * * * * * *
 * Draw my value in my color, left-justified.
 */
void Tile::draw() {
    cout << left;
    cout << "| " << "\033[38;5;" << color << "m" << setw(6) << value << "\033[38;5;15m" << "|";
    // TODO draw using hex color
}

/* * * * * * * * * * * * * * * * *
 * Double value and update color accordingly
 */
void Tile::increase() {
    value = value << 1;
    set_color();
}

int Tile::get_value() {
    return value;
}

void Tile::set_color() {
    switch(value) {
        case 2:
            color = "196";
            break;
        case 4:
            color = "208";
            break;
        case 8:
            color = "227";
            break;
        case 16:
            color = "114";
            break;
        case 32:
            color = "35";
            break;
        case 64:
            color = "33";
            break;
        case 128:
            color = "21";
            break;
        case 256:
            color = "54";
            break;
        case 512:
            color = "125";
            break;
        case 1024:
            color = "200";
            break;
        case 2048:
            color = "217";
            break;
        case 4096:
            color = "189";
            break;
        case 8192:
            color = "117";
            break;
        case 16384:
            color = "177";
            break;
        default:
            color = "15";
            break;
    }
}