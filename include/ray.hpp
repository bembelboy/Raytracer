#ifndef RAY_CLASS_HPP
#define RAY_CLASS_HPP

#include "point.hpp"
#include "vector.hpp"

using namespace math3d;

struct ray {
    //c'tors
    ray();
    ray(ray const& ray);
    ray(point const& origin, vector const& dir);
    ~ray();

    //methods
    ray& operator=(ray const& rhs); // assignment operator

    //member
    point origin_;
    vector direction_;

};
#endif //RAY_CLASS_HPP
