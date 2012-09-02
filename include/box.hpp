#ifndef BOX_CLASS_HPP
#define BOX_CLASS_HPP
#include "shape.hpp"

using namespace math3d;

class box : public shape {
    public:
        //Constructor and Destructor
        box();
        box(point const& p1, point const& p2);
        box(std::string const& name, point const& p1, point const& p2,
                material* mat_ptr);
        box(box const& b);
        ~box();

        //getter
        point const& get_min() const;
        point const& get_max() const;
        vector get_normal(int const face_hit) const;

        //methods
        /*virtual*/ bool intersect(ray const& ray, 
                hitpoint& hitP) const;
        /*virtual*/ double volume() const;
        /*virtual*/ double surface() const;
        /*virtual bool is_inside(point const& p) const;*/
        /*virtual*/ void print_on(std::ostream& os) const;

    private:
        point min_;
        point max_;
};

std::ostream& operator<<(std::ostream& os, material const& box);

#endif //BOX_CLASS_HPP
