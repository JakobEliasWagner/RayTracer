//
// Created by jakob on 12.02.22.
//

#include "lambertian.h"
#include "../utility/utility.h"

#include <utility>

Material::Lambertian::Lambertian(
        Colour::Colour colour)
        : albedo_(std::move(colour)) {

}

bool Material::Lambertian::Scatter(
        const Ray &ray_in,
        Ray &ray_out,
        const HitRecord &hit_record,
        Colour::Colour &attenuation) const {
    Vec3 scatter_direction = hit_record.normal + RandomUnitVec3InSphere();

    // Catch degenerate scatter
    if (utility::CloseToZero(scatter_direction)) {
        scatter_direction = hit_record.normal;
    }

    ray_out = Ray(hit_record.point, scatter_direction);
    attenuation = albedo_;
    return true;
}
