#ifndef SHAPE_CLASS_HPP
#define SHAPE_CLASS_HPP
#include <string>
#include "point.hpp"
#include "color.hpp"

//using math3d namespace;

class shape {
    public:
        //Constructor and Destructor
        shape();
        shape(shape const& s);
        shape(std::string const& name, color const& clr);
        virtual ~shape();

        //Methods
        virtual double volume() const = 0;
        virtual double surface() const = 0;
        virtual bool is_inside(math3d::point const& p) const = 0;
        virtual void print_on(std::ostream& out) const;

    protected:
        std::string name_;
        color color_;
};
std::ostream& operator <<(std::ostream& out, shape const& s);
#endif //SHAPE_CLASS_HPP
