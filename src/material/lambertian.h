//
// Created by jakob on 12.02.22.
//

#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H

#include "material.h"

namespace Material {
    class Lambertian : public MaterialInterface {
    public:
        Lambertian() = delete;

        Lambertian(Colour::Colour colour);

        bool Scatter(
                const Ray &ray_in,
                Ray &ray_out,
                const HitRecord &hit_record,
                Colour::Colour &attenuation
        ) const override;

        Colour::Colour albedo_;
    };
}


#endif //RAYTRACER_LAMBERTIAN_H
