#ifndef HITPOINT_CLASS_HPP
#define HITPOINT_CLASS_HPP

#include "point.hpp"
#include "vector.hpp"
#include "material.hpp"

using namespace math3d;

struct hitpoint {
    //c'tors
    hitpoint();
    hitpoint(hitpoint const& hp);
    ~hitpoint();

    //member
    point hitpoint_;  // hitpoint coordinates
    vector normal_;
    vector view_;     // ray direction
    double t_;        // distance along ray 
    material* material_ptr_;

    //methods
    bool operator<(hitpoint const& hp); //compares distances 
};

#endif //HITPOINT_CLASS_HPP
