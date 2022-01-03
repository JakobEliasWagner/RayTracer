//
// Created by jakob on 01.01.22.
//

#ifndef RAYTRACER_SIM_OBJECT_H
#define RAYTRACER_SIM_OBJECT_H

#include "../vec3/vec3.h"
#include "../camera/ray.h"

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double t;
    bool front_face;

    void SetFaceNormal(const Ray &ray, const Vec3 &outward_normal);
};

class SimObject {
public:
    virtual bool Hit(const Ray &ray,
                     const double &t_min,
                     const double &t_max,
                     HitRecord &record) const = 0;
};


#endif //RAYTRACER_SIM_OBJECT_H
