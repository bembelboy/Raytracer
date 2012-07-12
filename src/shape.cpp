#include "../include/shape.hpp"
#include "../include/color.hpp"
#include <string>
#include <iostream>

shape::shape()
    : name_("default"), color_(100, 100, 100) {}

shape::shape(shape const& s)
    : name_(s.name_), color_(s.color_) {}

shape::shape(std::string const& name, color const& clr)
    : name_(name), color_(clr) {}

shape::~shape() {
    //std::cout << "shape Destructor" << std::endl;
}

std::ostream& operator <<(std::ostream& out, shape const& s) {
    s.print_on(out);
    return out;
}

void shape::print_on(std::ostream& out) const {
    out << "name: " <<  name_ << " color: "
        << static_cast<unsigned>(color_[1]) << ","
        << static_cast<unsigned>(color_[2]) << ","
        << static_cast<unsigned>(color_[3]) << " ";
}

