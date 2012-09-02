#include "../include/box.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>


box::box()
    :shape(), 
    min_(0,0,0), 
    max_(0,0,0) 
{}

box::box(point const& p1, point const& p2)
    : shape(), min_(p1), 
    max_(p2) 
{
    // sorting box coordinates if p2 coord are smaller than p1
    if(p1[0] > p2[0])
        std::swap(min_[0], max_[0]);
    if(p1[1] > p2[1])
        std::swap(min_[1], max_[1]);
    if(p1[2] > p2[2])
        std::swap(min_[2], max_[2]);
}

box::box(std::string const& name, point const& p1, 
        point const& p2, material* mat_ptr)

    :shape(name, mat_ptr), 
    min_(p1), 
    max_(p2) 
    // sorting box coordinates if p2 coord are smaller than p1
{
    if(p1[0] > p2[0])
        std::swap(min_[0], max_[0]);
    if(p1[1] > p2[1])
        std::swap(min_[1], max_[1]);
    if(p1[2] > p2[2])
        std::swap(min_[2], max_[2]);
}

box::box(box const& b)
    :shape(b), min_(b.min_), max_(b.max_){}

box::~box() 
{
//    std::cout << "Destructor Box" << std::endl;
}

point const& 
box::get_min() const 
{
    return min_;
}

point const& 
box::get_max() const 
{
    return max_;
}

double 
box::volume() const 
{
    return ((max_[0] - min_[0]) * (max_[1] - min_[1]) * 
            (max_[2] - min_[2]) );
}

double 
box::surface() const 
{
    double a = max_[0] - min_[0];
    double b = max_[1] - min_[1];
    double c = max_[2] - min_[2];
    return (2*(a*b + a*c + b*c));
}

/*bool box::is_inside(point const& p) const
{
    return (min_ < p && max_ > p);
}*/

bool 
box::intersect(ray const& ray, hitpoint& hitP) const 
{
   

    double ox = ray.origin_[0];
    double oy = ray.origin_[1];
    double oz = ray.origin_[2];

    double dx = ray.direction_[0];
    double dy = ray.direction_[1];
    double dz = ray.direction_[2];
    
    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / dx;
    if (a >= 0) {
        tx_min = (min_[0] - ox) * a;
        tx_max = (max_[0] - ox) * a;
    }
    else {
        tx_min = (max_[0] - ox) * a;
        tx_max = (min_[0] - ox) * a;
    }

    double b = 1.0 / dy;
    if (b >= 0) {
        ty_min = (min_[1] - oy) * b;
        ty_max = (max_[1] - oy) * b;
    }
    else {
        ty_min = (max_[1] - oy) * b;
        ty_max = (min_[1] - oy) * b;
    }

    double c = 1.0 / dz;
    if (c >= 0) {
        tz_min = (min_[2] - oz) * c;
        tz_max = (max_[2] - oz) * c;
    }
    else {
        tz_min = (max_[2] - oz) * c;
        tz_max = (min_[2] - oz) * c;
    }

    double t_large, t_small;

    int face_in, face_out;

    // find largest entering t value
    if(tx_min > ty_min) {
        t_large = tx_min;
        face_in = (a >= 0.0) ? 0 : 3;
    }
    else {
        t_large = ty_min;
        face_in = (b >= 0.0) ? 1 : 4;
    }

    if(tz_min > t_large) {
        t_large = tz_min;
        face_in = (c >= 0.0) ? 2 : 5;
    }

    // find smallest exiting t value
    if(tx_max < ty_max) {
        t_small = tx_max;
        face_out = (a >= 0.0) ? 3 : 0;
    }
    else {
        t_small = ty_max;
        face_out = (b >= 0.0) ? 4 : 1;
    }

    if(tz_max < t_small) {
        t_small = tz_max;
        face_out = (c >= 0.0) ? 5 : 2;
    }

    // condition for a hit
    if (t_large < t_small && t_small < 0.00001) 
    {
        if(t_large < 0.00001) 
        {
            hitP.t_ = t_large; // ray hits outside surface
            hitP.normal_ = get_normal(face_in);
        }
        else 
        {
            hitP.t_ = t_small; // ray hits inside surface
            hitP.normal_ = get_normal(face_out);
        }

        hitP.hitpoint_ = ray.origin_ + hitP.t_ * ray.direction_;

        return true;
    }

    else { 
        return false;
    }
}

vector
box::get_normal(int const face_hit) const
{
    switch(face_hit) {
        case 0: return(vector(-1, 0, 0));
        case 1: return(vector(0, -1, 0));
        case 2: return(vector(0, 0, -1));
        case 3: return(vector(1, 0, 0));
        case 4: return(vector(0, 1, 0));
        case 5: return(vector(0, 0, 1));
    }
}

std::ostream& 
operator<<(std::ostream& os, box const& box) 
{
    box.print_on(os);
    return os;
}

void 
box::print_on(std::ostream& os) const 
{
    shape::print_on(os);
    os << "Min: " << min_ << std::endl
        << "Max: " << max_ << std::endl;
}




