#include <iostream>
#include <memory>

#include "src/vec3/colour.h"
#include "src/vec3/vec3.h"
#include "src/camera/camera.h"
#include "src/sim_objects/sim_object_list.h"
#include "src/sim_objects/sphere.h"
#include "src/utility/utility.h"


Colour::Colour ray_colour(const Ray &ray, const SimObject &world,
                          const unsigned int &bounces) {
    if (bounces <= 0) return Colour::Colour(0., 0., 0.);

    HitRecord record;
    if (world.Hit(ray, 0.001, Constants::infinity, record)) {
        Point3 target{record.point + record.normal + RandomUnitVec3InSphere()};
        return 0.5 * ray_colour(Ray(record.point, target - record.point),
                                world,
                                bounces - 1);
    }

    auto t = 0.5 * (ray.Direction().y() + 1.);
    return (1. - t) * Colour::Colour(1., 1., 1.) +
           t * Colour::Colour(.5, .7, 1.);
}

int main() {
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width{400};
    const int image_height{static_cast<int>(image_width / aspect_ratio)};
    const unsigned int samples_per_pixel{20};
    const unsigned int max_bounces{10};

    // World
    SimObjectList world;
    world.Add(std::make_shared<Sphere>(Point3(0., 0., -1), .5));
    world.Add(std::make_shared<Sphere>(Point3(0., -1000000.5, -1), 1000000));

    // Camera
    Camera camera;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i) {
        std::cerr << "\rLines remaining: " << i << " " << std::flush;

        for (int j = 0; j <= image_width - 1; ++j) {
            Colour::Colour pixel_colour{0, 0, 0};
            for (int sample = 0; sample < samples_per_pixel; ++sample) {
                auto u = (double(j) + utility::GetRandom(-1., 1.)) /
                         (image_width - 1);
                auto v = (double(i) + utility::GetRandom(-1., 1.)) /
                         (image_height - 1);

                Ray r = camera.GetRay(u, v);

                pixel_colour += ray_colour(r, world, max_bounces);
            }
            Colour::Write(std::cout, pixel_colour, samples_per_pixel);
        }
    }
    std::cerr << "\nDone\n";
}
