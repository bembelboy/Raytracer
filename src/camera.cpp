#include "../include/camera.hpp"

#include <cmath>
#include <iostream>


camera::camera() 
    :name_("default"),
    eye_(0.0,0.0,0.0),
    fovX_(0),
    distance_(500.0)
    //lookat_(0.0,0.0,0.0),
    //up_(0,1,0),
    //u_(1,0,0), v_(0,1,0), w_(0,0,1),
{}

camera::camera(camera const& cam)
    :name_(cam.name_),
    eye_(cam.eye_),
    fovX_(cam.fovX_),
    distance_(cam.distance_)
    //lookat_(cam.lookat_),
    //up_(cam.up_),
    //u_(cam.u_), v_(cam.v_), w_(cam.w_),
{}

camera::camera(std::string const& name, float fovX) 
    :name_(name),
    //lookat_(lookat),
    //up_(up),
    //u_(1,0,0), v_(0,1,0), w_(0,0,1),
    fovX_(fovX)
{
    distance_ = ( 0.5 * 800) / tan(0.5 * (fovX * M_PI / 180));

    eye_ = point(0.0,0.0,distance_);
}

camera::~camera()
{}

point const& 
camera::get_eye() const
{
    return eye_;
}

vector
camera::calc_eye_ray(point const& p) const {
   
    vector u(1.0,0.0,0.0);
    vector v(0.0,1.0,0.0);
    vector w(0.0,0.0,1.0);

    vector dir = p[0] * u + p[1] * v - distance_ * w;
    dir.normalize();
   
    return (dir);
}


//    void
//    camera::compute_uvw() {
//        w_ = eye_ - lookat_;
//        w_.normalize();
//        u_ = cross(up_, w_);
//        v_ = cross(w_, u_);
//    }

//    void
//    camera::set_eye(point p) {
//    eye_ = p;
//    }
//    
//    void
//    camera::set_lookat(point p) {
//    lookat_ = p;
//    }
//    
//    void
//    camera::set_up_vector(vector v) {
//    up_ = v;
//    }
//    
//    void
//    camera::set_fovX(float angle) {
//    fovX_ = angle;
//    }
//    
std::ostream&
operator<<(std::ostream& os, camera const& cam) {
    cam.print_on(os);
    return os;
}

void
camera::print_on(std::ostream& os) const {
    os << "Name: " << name_ << std::endl
        << "fovX = " << fovX_ << " " << std::endl
        << "Position: " << eye_ ;
}
