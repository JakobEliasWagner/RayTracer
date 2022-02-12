//
// Created by jakob on 23.12.21.
//

#include "colour.h"
#include "../utility/utility.h"

void Colour::Write(std::ostream &out,
                   const Colour &pixel_colour,
                   const unsigned int &samples_per_pixel) {
    auto r{pixel_colour.x()};
    auto g{pixel_colour.y()};
    auto b{pixel_colour.z()};

    // Gamma-correct gamma=2.0
    auto scale = 1.0 / samples_per_pixel;

    r = std::sqrt(r * scale);
    g = std::sqrt(g * scale);
    b = std::sqrt(b * scale);

    out << static_cast<int>(256 * utility::clamp(r, 0.0, 0.999)) << " "
        << static_cast<int>(256 * utility::clamp(g, 0.0, 0.999)) << " "
        << static_cast<int>(256 * utility::clamp(b, 0.0, 0.999)) << "\n";
}