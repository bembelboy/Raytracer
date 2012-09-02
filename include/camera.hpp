#ifndef CAMERA_CLASS_HPP
#define CAMERA_CLASS_HPP

#include <string>
#include "point.hpp"
#include "vector.hpp"
#include "ray.hpp"

using namespace math3d;

class camera {
    public:
        //c'tors
        camera();
        camera(camera const& cam);
        camera(std::string const& name, float fovX); 
        ~camera();

        //void compute_uvw(); //compute local coordinate 
            //system for camera
        
        vector calc_eye_ray(point const& p) const;
        point const& get_eye() const;
        void print_on(std::ostream& os) const;

        //void set_eye(point p);
        //void set_lookat(point p);
        //void set_up_vector(vector v);
        //void set_fovX(float angle);

    private:
        std::string name_;
        point eye_;
        //point lookat_;
        //vector up_;
        //vector u_, v_, w_;
        float fovX_; // roll angle
        float distance_;
};

std::ostream& operator<<(std::ostream& os, camera const& cam);

#endif //CAMERA_CLASS_HPP
