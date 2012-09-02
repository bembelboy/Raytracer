#ifndef SPHERE_CLASS_HPP
#define SPHERE_CLASS_HPP

#include "shape.hpp"

using namespace math3d;

class sphere : public shape {
    public:
        //Constructors and Desructor
        sphere();
        sphere(point const& center, double r);
        sphere(std::string const& name, point const& center, double r,
                 material* mat_ptr);
        sphere(sphere const& sp);
        ~sphere();

        //Getter
        double get_radius() const;
        math3d::point const& get_center() const;

        //methods
        /*virtual*/ bool intersect(ray const& ray, hitpoint& hitP) const;
        /*vitrual*/ double volume() const;
        /*virtual*/ double surface() const;
        //*virtual*/ bool is_inside(math3d::point const& p) const;
        /*virtual*/ void print_on(std::ostream& os) const;

    private:
        point center_;
        double radius_;
};

std::ostream& operator<<(std::ostream& os, sphere const& sph);

#endif //SPHERE_CLASS_HPP
