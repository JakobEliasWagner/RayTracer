//
// Created by jakob on 02.01.22.
//

#ifndef RAYTRACER_UTILITY_H
#define RAYTRACER_UTILITY_H

#include <cstdlib>
#include <random>

#include "constants.h"

namespace utility {
    inline double DegreesToRadians(double degrees) {
        return degrees * Constants::pi / 180.;
    }

    inline double RadiansToDegrees(double radians) {
        return radians * 180. / Constants::pi;
    }

    template<typename t>
    inline t GetRandom(t left, t right) {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_real_distribution <t> dist(left, right);

        return dist(eng);
    }

    template<typename t>
    inline t GetRandom() {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_real_distribution<t> dist(-1., 1.);

        return dist(eng);
    }

    inline double clamp(double x, double min, double max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
}


#endif //RAYTRACER_UTILITY_H
