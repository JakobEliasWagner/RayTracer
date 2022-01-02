//
// Created by jakob on 01.01.22.
//

#ifndef RAYTRACER_SIM_OBJECT_LIST_H
#define RAYTRACER_SIM_OBJECT_LIST_H

#include <memory>
#include <vector>

#include "sim_object.h"

class SimObjectList : public SimObject {
public:
    SimObjectList() = default;

    SimObjectList(const std::shared_ptr<SimObject> &object);

    void Add(std::shared_ptr<SimObject> object);

    bool Hit(const Ray &ray,
             const double &t_min,
             const double &t_max,
             HitRecord &record) const override;

private:
    std::vector<std::shared_ptr<SimObject>> sim_objects_;
};


#endif //RAYTRACER_SIM_OBJECT_LIST_H
