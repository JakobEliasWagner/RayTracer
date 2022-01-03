//
// Created by jakob on 01.01.22.
//

#include "sphere.h"

#include <utility>

Sphere::Sphere(Point3 center, const double &radius) :
        center_(std::move(center)), radius_(radius) {

}

bool Sphere::Hit(const Ray &ray, const double &t_min, const double &t_max,
                 HitRecord &record) const {
    Vec3 oc = ray.Origin() - center_;

    auto a = ray.Direction().dot(ray.Direction());
    auto b = 2. * oc.dot(ray.Direction());
    auto c = oc.dot(oc) - radius_ * radius_;

    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }

    auto root_discriminant = sqrt(discriminant);

    // Find the closes root in t-range
    auto root = (-b - sqrt(discriminant)) / (2. * a);

    if (root > t_max) return false;  // smaller root too big

    if (root < t_min) {
        root = (-b + sqrt(discriminant)) / (2. * a);
        if (root > t_max)
        {
            return false;  // bigger root too big and smaller too small
        } else if (root < t_min) {
            return false;
        }

    }

    record.t = root;
    record.point = ray.AtT(root);

    auto outward_normal = (record.point - center_) / radius_;
    record.SetFaceNormal(ray, outward_normal);

    return true;
    /*
    Vec3 oc = ray.Origin() - center_;
    auto a = ray.Direction().dot(ray.Direction());
    auto half_b = oc.dot(ray.Direction());
    auto c = oc.dot(oc) - radius_ * radius_;
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);
    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }
    record.t = root;
    record.point = ray.AtT(root);
    record.normal = (record.point - center_) / radius_;
    return true;*/
}
