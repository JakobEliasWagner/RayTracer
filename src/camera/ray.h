//
// Created by jakob on 23.12.21.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../vec3/vec3.h"
#include "../vec3/colour.h"


class Ray {
public:
    Ray() = default;

    Ray(Point3 origin, const Vec3& direction);

    [[nodiscard]] Point3 Origin() const;

    [[nodiscard]] Vec3 Direction() const;

    /*
     * returns point of where the ray is at a specific time
     */
    [[nodiscard]] Point3 AtT(const double &time) const;

private:
    Point3 origin_;
    Vec3 direction_;  // Always of length one
};


#endif //RAYTRACER_RAY_H
