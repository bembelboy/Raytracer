#ifndef BOX_CLASS_HPP
#define BOX_CLASS_HPP
#include "shape.hpp"

using namespace math3d;

class box : public shape {
    public:
        //Constructor and Destructor
        box();
        box(point const& one, point const& two);
        box(point const& one, point const& two,
                std::string const& name, color const& clr);
        box(box const& b);
        ~box();

        //getter
        point const& get_min() const;
        point const& get_max() const;

        //methods
        /*virtual*/ double volume() const;
        /*virtual*/ double surface() const;
        /*virtual bool is_inside(point const& p) const;*/
        /*virtual*/ void print_on(std::ostream& out) const;

    private:
        point min_;
        point max_;
};
#endif //BOX_CLASS_HPP
