//
// Created by jakob on 23.12.21.
//

#include "colour.h"

void Colour::Write(std::ostream &out, const Colour &pixel_colour) {
    out << static_cast<int>(255.999 * pixel_colour.x()) << " "
        << static_cast<int>(255.999 * pixel_colour.y()) << " "
        << static_cast<int>(255.999 * pixel_colour.z()) << "\n";
}