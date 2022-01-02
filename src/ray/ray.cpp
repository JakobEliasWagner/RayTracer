//
// Created by jakob on 23.12.21.
//

#include "ray.h"

#include <utility>

Ray::Ray(Point3 origin,
         const Vec3 &direction) :
        origin_(std::move(origin)),
        direction_(direction.normalized()) {

}

Vec3 Ray::Direction() const {
    return direction_;
}

Point3 Ray::AtT(const double &time) const {
    return origin_ + time * direction_;
}

Point3 Ray::Origin() const {
    return origin_;
}
