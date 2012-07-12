#include "../include/point.hpp"
#include "../include/sphere.hpp"
#include <iostream>
#include <cmath>


sphere::sphere()
    :shape(), center_(0, 0, 0), radius_(0) {}

sphere::sphere(point const& center, double r)
    :shape(), center_(center), radius_(r) {}

sphere::sphere(point const& center, double r,
        std::string const& name, color const& clr)
    :shape(name, clr), center_(center), radius_(r) {}

sphere::sphere(sphere const& sp)
    :shape(sp), center_(sp.center_), radius_(sp.radius_) {}

sphere::~sphere() {
    std::cout << "Sphere Destructor" << std::endl;
}

double sphere::get_radius() const {
    return radius_;
}

point const& sphere::get_center() const{
    return center_;
}

double sphere::volume() const {
    return((4.0/3.0)*M_PI*pow(radius_, 3));
}

double sphere::surface() const {
    return (4.0 * M_PI * radius_ * radius_);
}

bool sphere::is_inside(point const& p) const {
    return distance(p, center_) < radius_;
}

void sphere::print_on(std::ostream& out) const {
    shape::print_on(out);
    out << "center: "
        << static_cast<unsigned>(center_[0]) << ","
        << static_cast<unsigned>(center_[1]) << ","
        << static_cast<unsigned>(center_[2]) << " "
        << " radius: " << radius_ << std::endl;
}
