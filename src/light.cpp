#include "../include/light.hpp"
#include <iostream>

Light::Light()
    :name_("default"), 
    pos_(100.0,100.0,100.0),
    La_(50,50,50),
    Ld_(10,10,10)
{}

Light::Light(Light const& Light)
    :name_(Light.name_),
    pos_(Light.pos_),
    La_(Light.La_),
    Ld_(Light.Ld_)
{}

Light::Light(std::string const& name, point const& pos,
        color const& La, color const& Ld)
    :name_(name),
     pos_(pos),
     La_(La),
     Ld_(Ld)
{}

Light::~Light()
{}

std::ostream& 
operator<<(std::ostream& os, Light const& light) {
    light.print_on(os);
    return os;
}

void 
Light::print_on(std::ostream& os) const {
    os << "Name: " << name_ << std::endl
        << "Position: " << pos_ << std::endl 
        << "Ambient Light: "; 
        La_.color::print(os);
    os  << "Difuse Light: ";
        Ld_.color::print(os); 
}
