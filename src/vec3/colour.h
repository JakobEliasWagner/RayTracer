//
// Created by jakob on 23.12.21.
//

#ifndef RAYTRACER_COLOUR_H
#define RAYTRACER_COLOUR_H

#include "vec3.h"
#include <iostream>

namespace Colour {
    using Colour = Eigen::Vector3d;

    void Write(std::ostream &out,
               const Colour &pixel_colour,
               const unsigned int &samples_per_pixel);
}


#endif //RAYTRACER_COLOUR_H
