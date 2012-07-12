#include "../include/box.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>


box::box()
    :shape(), min_(0,0,0), max_(0,0,0) {}

box::box(point const& one, point const& two)
    : shape(), min_(one), max_(two) {
    if(one[0] > two[0])
        std::swap(min_[0], max_[0]);
    if(one[1] > two[1])
        std::swap(min_[1], max_[1]);
    if(one[2] > two[2])
        std::swap(min_[2], max_[2]);
}

box::box(point const& one, point const& two,
        std::string const& name, color const& clr)
    :shape(name, clr), min_(one), max_(two) {
    if(one[0] > two[0])
        std::swap(min_[0], max_[0]);
    if(one[1] > two[1])
        std::swap(min_[1], max_[1]);
    if(one[2] > two[2])
        std::swap(min_[2], max_[2]);
}

box::box(box const& b)
    :shape(b), min_(b.min_), max_(b.max_){}

box::~box() {
//    std::cout << "Destructor Box" << std::endl;
}

point const& box::get_min() const {
    return min_;
}

point const& box::get_max() const {
    return max_;
}

double box::volume() const {
    return ((max_[0] - min_[0]) * (max_[1] - min_[1]) * (max_[2] - min_[2]) );
}

double box::surface() const {
    double a = max_[0] - min_[0];
    double b = max_[1] - min_[1];
    double c = max_[2] - min_[2];
    return (2*(a*b + a*c + b*c));
}

/*bool box::is_inside(point const& p) const{
    return (min_ < p && max_ > p);
}*/

void box::print_on(std::ostream& out) const {
    shape::print_on(out);
    out << "min: "
        <<  min_[0] << ","
        <<  min_[1] << ","
        <<  min_[2] << " "
        << " max: "
        << max_[0] << ","
        << max_[1] << ","
        << max_[2] << " ";
}




