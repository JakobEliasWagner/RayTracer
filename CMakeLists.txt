cmake_minimum_required(VERSION 3.19)
project(RayTracer)

set(CMAKE_CXX_STANDARD 20)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (Boost)

add_executable(RayTracer
        main.cpp
        src/vec3/vec3.cpp
        src/vec3/vec3.h
        src/vec3/colour.cpp
        src/vec3/colour.h
        src/camera/ray.cpp
        src/camera/ray.h
        src/camera/camera.cpp
        src/camera/camera.h
        src/sim_objects/sim_object.cpp
        src/sim_objects/sim_object.h
        src/sim_objects/sphere.cpp
        src/sim_objects/sphere.h
        src/sim_objects/sim_object_list.cpp
        src/sim_objects/sim_object_list.h
        src/utility/constants.h)

target_link_libraries (RayTracer Eigen3::Eigen)
target_link_libraries(RayTracer ${Boost_LIBRARIES})