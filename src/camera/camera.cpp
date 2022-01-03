//
// Created by jakob on 02.01.22.
//

#include "camera.h"

Camera::Camera() {
    viewport_width_ = aspect_ratio_ * viewport_height_;
    horizontal_ = Vec3(viewport_width_, 0., 0.);
    vertical_ = Vec3(0., viewport_height_, 0.);
    lateral_ = Vec3(0., 0., focal_length_);
    lower_left_corner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - lateral_;
}

Ray Camera::GetRay(double u, double v) {
    return Ray(origin_, lower_left_corner_ + u * horizontal_ + v * vertical_ - origin_);
}
