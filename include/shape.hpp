#ifndef SHAPE_CLASS_HPP
#define SHAPE_CLASS_HPP
#include <string>
#include "point.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
#include "material.hpp"

using namespace math3d;

class shape {
    public:
        // c'tors
        shape();
        shape(std::string const& name, material* mat_ptr);
        virtual ~shape();

        //Methods
        virtual bool intersect(ray const& ray, hitpoint& hitP) const = 0;
        virtual double volume() const = 0;
        virtual double surface() const = 0;
        //virtual bool is_inside(point const& p) const = 0;
        virtual void print_on(std::ostream& os) const;

    protected:
        std::string name_;
        material* material_ptr_;
};

std::ostream& operator<<(std::ostream& os, shape const& s);

#endif // SHAPE_CLASS_HPP
