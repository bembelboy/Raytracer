#include "../include/sphere.hpp"
#include "../include/point.hpp"
#include "../include/vector.hpp"

#include <iostream>
#include <cmath>

sphere::sphere()
    :shape(), 
    center_(0, 0, 0), 
    radius_(0) 
{}

sphere::sphere(point const& center, double r)
    :shape(), 
    center_(center), 
    radius_(r) 
{}

sphere::sphere(std::string const& name, point const& center, double r,
        material* mat_ptr)
    :shape(name, mat_ptr), 
    center_(center), 
    radius_(r) 
{}

sphere::sphere(sphere const& sp)
    :shape(sp), 
    center_(sp.center_), 
    radius_(sp.radius_) 
{}

sphere::~sphere() 
{
    std::cout << "Sphere Destructor" << std::endl;
}

double 
sphere::get_radius() const 
{
    return radius_;
}

point const& 
sphere::get_center() const
{
    return center_;
}

double 
sphere::volume() const 
{
    return((4.0/3.0)*M_PI*pow(radius_, 3));
}

double 
sphere::surface() const 
{
    return (4.0 * M_PI * radius_ * radius_);
}

//    bool sphere::is_inside(point const& p) const {
//        return distance(p, center_) < radius_;
//    }

bool 
sphere::intersect(ray const& ray, hitpoint& hitP) const 
{
    
    double t; 
    vector p_0 = ray.origin_ - center_;
    double a = dot(ray.direction_, ray.direction_); 
    double b = 2.0 * dot(p_0, ray.direction_);
    double c = dot(p_0, p_0) - radius_ * radius_;
    double disc = b * b - 4.0 * a * c; // discriminant of the quadratic equation

    if(disc < 0.0) 
        return false;
    
    else {
        double e = std::sqrt(disc);           
        double denominator = 2.0 * a;        // of the quadratic equation 
        t = (-b - e) / denominator;
        
        if(t > 0.00001) {
            hitP.t_ = t;
            hitP.normal_ = (p_0 + t * ray.direction_) / radius_;
            hitP.normal_.normalize();
            hitP.hitpoint_ = ray.origin_ + (t * ray.direction_);            
            return true;
        }

        t = (-b + e) / denominator;

        if(t > 0.00001) {
            hitP.t_ = t;
            hitP.normal_ = (p_0 + t * ray.direction_) / radius_;
            hitP.normal_.normalize();
            hitP.hitpoint_ = ray.origin_ + (t * ray.direction_);            
            return true;
        }
    }
    
    return false;
}

std::ostream& operator <<(std::ostream& os, sphere const& sph) {
    sph.print_on(os);
    return os;
}

void sphere::print_on(std::ostream& os) const {
    shape::print_on(os);
    os << "Center: " << center_ << std::endl
        //<< static_cast<unsigned>(center_[0]) << ","
        //<< static_cast<unsigned>(center_[1]) << ","
        //<< static_cast<unsigned>(center_[2]) << "] "
        << "Radius = " << radius_ << std::endl;
}
