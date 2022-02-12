//
// Created by jakob on 12.02.22.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "../camera/ray.h"
#include "../sim_objects/sim_object.h"

struct HitRecord;

class MaterialInterface {
public:
    virtual bool Scatter(
            const Ray &ray_in,
            Ray &ray_out,
            const HitRecord &hit_record,
            Colour::Colour &attenuation
    ) const = 0;
};


#endif //RAYTRACER_MATERIAL_H
