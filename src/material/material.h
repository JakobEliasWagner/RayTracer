//
// Created by jakob on 12.02.22.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "../camera/ray.h"

struct HitRecord;

class Material {
public:
    virtual bool scatter(
            const Ray &ray_in,
            Ray &ray_out,
            const HitRecord &hit_record,
            Colour::Colour &attenuation
    ) const = 0;
};


#endif //RAYTRACER_MATERIAL_H
