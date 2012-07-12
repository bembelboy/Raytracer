#ifndef SPHERE_CLASS_HPP
#define SPHERE_CLASS_HPP
#include "shape.hpp"
#include "../include/point.hpp"

using namespace math3d;

class sphere : public shape {
    public:
        //Constructors and Desructor
        sphere();
        sphere(math3d::point const& center, double r);
        sphere(math3d::point const& center, double r,
                std::string const& name, color const& clr);
        sphere(sphere const& sp);
        ~sphere();

        //Getter
        double get_radius() const;
        math3d::point const& get_center() const;

        //methods
        /*vitrual*/ double volume() const;
        /*virtual*/ double surface() const;
        /*virtual*/ bool is_inside(math3d::point const& p) const;
        /*virtua*/ void print_on(std::ostream& out) const;

    private:
        math3d::point center_;
        double radius_;
};
#endif //SPHERE_CLASS_HPP
