#include "../include/ray.hpp"

ray::ray()
    :origin_(),
    direction_()
{}

ray::ray(ray const& ray)
    :origin_(ray.origin_),
    direction_(ray.direction_)
{}

ray::ray(point const& origin, vector const& dir)
    :origin_(origin),
    direction_(dir)
{}

ray::~ray()
{}

ray&
ray::operator=(ray const& rhs) {
    if (this == &rhs)  // self assignment case
        return (*this);

    origin_ = rhs.origin_;
    direction_ = rhs.direction_;
    return(*this);
}
