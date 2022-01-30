//
// Created by jakob on 14.12.21.
//

#include "vec3.h"
#include "../utility/utility.h"

Vec3 RandomVec3InSphere(double r) {
    while (true) {
        Vec3 rand{utility::GetRandom(-r, r), utility::GetRandom(-r, r),
                  utility::GetRandom(-r, r)};
        if (rand.norm() < r) return rand;
    }
}

Vec3 RandomVec3InSphere() {
    while (true) {
        Vec3 rand{utility::GetRandom(-1., 1.), utility::GetRandom(-1., 1.),
                  utility::GetRandom(-1., 1.)};
        if (rand.norm() < 1.) return rand;
    }
}
