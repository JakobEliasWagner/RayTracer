//
// Created by jakob on 01.01.22.
//

#include "sim_object_list.h"

SimObjectList::SimObjectList(const std::shared_ptr<SimObject> &object) {
    Add(object);
}

void SimObjectList::Add(std::shared_ptr<SimObject> object) {
    sim_objects_.push_back(object);
}

bool SimObjectList::Hit(const Ray &ray,
                        const double &t_min,
                        const double &t_max,
                        HitRecord &record) const {
    bool hit_anything = false;
    HitRecord tmp_record;
    auto closest{t_max};

    for (const auto &obj: sim_objects_) {
        if (obj->Hit(ray, t_min, closest, tmp_record)) {
            hit_anything = true;
            closest = tmp_record.t;
            record = tmp_record;
        }
    }

    return hit_anything;
}
