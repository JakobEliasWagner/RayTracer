//
// Created by jakob on 12.02.22.
//

#ifndef RAYTRACER_METAL_H
#define RAYTRACER_METAL_H

#include "material.h"

namespace Material {
    class Metal : public MaterialInterface {
    public:
        Metal() = delete;

        explicit Metal(Colour::Colour colour);

        bool Scatter(
                const Ray &ray_in,
                Ray &ray_out,
                const HitRecord &hit_record,
                Colour::Colour &attenuation
        ) const override;

        Colour::Colour albedo_;
    };
}


#endif //RAYTRACER_METAL_H
