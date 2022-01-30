//
// Created by jakob on 14.12.21.
//

#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

#include <vector>
#include <Eigen/Dense>

#include "colour.h"


using Point3 = Eigen::Vector3d;
using Vec3 = Eigen::Vector3d;

Vec3 RandomVec3InSphere(double r);
Vec3 RandomVec3InSphere();

#endif //RAYTRACER_VEC3_H
