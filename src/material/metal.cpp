//
// Created by jakob on 12.02.22.
//

#include "metal.h"

#include <utility>

Material::Metal::Metal(Colour::Colour colour) : albedo_(std::move(colour)) {

}

bool Material::Metal::Scatter(const Ray &ray_in, Ray &ray_out,
                              const HitRecord &hit_record,
                              Colour::Colour &attenuation) const {
    Vec3 reflected = ray_in.Direction() -
                     2 * ray_in.Direction().dot(hit_record.normal) *
                     hit_record.normal;

    ray_out = Ray(hit_record.point, reflected);

    attenuation = albedo_;

    return (ray_out.Direction().dot(hit_record.normal) > 0);
}
