//
// Created by jakob on 01.01.22.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "sim_object.h"

class Sphere : public SimObject {
public:
    Sphere() = delete;

    Sphere(Point3 center,
           const double &radius,
           std::shared_ptr<MaterialInterface>  material);

    bool Hit(const Ray &ray,
             const double &t_min,
             const double &t_max,
             HitRecord &record) const override;

private:
    double radius_;
    Point3 center_;
    std::shared_ptr<MaterialInterface> material_;
};


#endif //RAYTRACER_SPHERE_H
