#include <iostream>
#include <memory>

#include "src/vec3/colour.h"
#include "src/vec3/vec3.h"
#include "src/ray/ray.h"
#include "src/sim_objects/sim_object_list.h"
#include "src/sim_objects/sphere.h"
#include "src/utility/constants.h"


Colour::Colour ray_color(const Ray &ray, const SimObject &world) {
    HitRecord record;
    if (world.Hit(ray, 0, Constants::infinity, record)){
        return 0.5 * (record.normal + Colour::Colour(1., 1., 1.));
    }

    auto t = 0.5 * (ray.Direction().y() + 1.);
    return (1. - t) * Colour::Colour(1., 1., 1.) +
           t * Colour::Colour(.5, .7, 1.);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width{1000};
    const int image_height{static_cast<int>(image_width / aspect_ratio)};

    // World
    SimObjectList world;
    world.Add(std::make_shared<Sphere>(Point3(0, 0, -1), .5));
    world.Add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

    // Camera
    const auto viewport_height{2.0};
    const auto viewport_width{aspect_ratio * viewport_height};
    const auto focal_length{1.0};

    const auto origin = Point3(0., 0., 0.);
    const auto horizontal = Vec3(viewport_width, 0, 0);
    const auto vertical = Vec3(0, viewport_height, 0);
    const auto lateral = Vec3(0, 0, focal_length);
    const auto lower_left_corner =
            origin - horizontal / 2 - vertical / 2 -
            lateral;  // Todo find weird behaviour bug due to replacing lateral with Vec3(0, 0, focal_length)


    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i) {
        std::cerr << "\rLines remaining: " << i << " " << std::flush;
        for (int j = 0; j <= image_width - 1; ++j) {

            auto u = double(j) / (image_width - 1);
            auto v = double(i) / (image_height - 1);

            Ray r(origin,
                  lower_left_corner + u * horizontal + v * vertical - origin);

            Colour::Colour pixel_colour = ray_color(r, world);
            Colour::Write(std::cout, pixel_colour);
        }
    }
    std::cerr << "\nDone\n";
}
