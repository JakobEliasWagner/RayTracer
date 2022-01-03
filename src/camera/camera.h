//
// Created by jakob on 02.01.22.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../vec3/vec3.h"
#include "ray.h"

class Camera {
public:
    Camera();

    Ray GetRay(double u, double v);

private:
    double aspect_ratio_{16. / 9.};
    double viewport_height_{2.};
    double focal_length_{1.};

    Point3 origin_{0, 0, 0};

    Vec3 horizontal_;
    Vec3 vertical_;
    Vec3 lateral_;
    Vec3 lower_left_corner_;
    double viewport_width_;

};


#endif //RAYTRACER_CAMERA_H
