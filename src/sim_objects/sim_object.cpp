//
// Created by jakob on 01.01.22.
//

#include "sim_object.h"

void HitRecord::SetFaceNormal(const Ray &ray, const Vec3 &outward_normal) {
    bool is_front_face = ray.Direction().dot(outward_normal) < 0;
    normal = is_front_face ? outward_normal : -outward_normal;
}
