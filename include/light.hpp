#ifndef LIGHT_CLASS_HPP
#define LIGHT_CLASS_HPP

#include <string>
#include "point.hpp"
#include "color.hpp"

using namespace math3d;

struct Light {
    //c'tors
    Light();
    Light(Light const& Light);
    Light(std::string const& name, point const& pos, color const& ambient, color const& diffuse);
    ~Light();

    //member
    std::string name_;
    point pos_;
    color La_;
    color Ld_;

    //methods
    void print_on(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Light const& light);

#endif //LIGHT_CLASS_HPP
