//
// Created by jakob on 01.01.22.
//

#include "sphere.h"

#include <utility>

Sphere::Sphere(Point3 center,
               const double &radius,
               std::shared_ptr<MaterialInterface> material)
        : center_(std::move(center)),
          radius_(radius),
          material_(std::move(material)) {

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
        if (root > t_max || root < t_min) {
            return false;  // bigger root too big and smaller too small
        }
    }

    record.t = root;
    record.point = ray.AtT(root);

    auto outward_normal = (record.point - center_) / radius_;
    record.SetFaceNormal(ray, outward_normal);

    record.material = material_;

    return true;
}
