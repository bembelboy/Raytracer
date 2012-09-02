#include "../include/renderer.hpp"
#include "../include/glutwindow.hpp"
#include "../include/pixel.hpp"
#include "../include/hitpoint.hpp"
#include "../include/ray.hpp"
#include "../include/camera.hpp"
#include "../include/shape.hpp"

#include <iostream>

renderer::renderer(scene const& sc)
    :sc_(sc),
    window_(glutwindow::instance()),
    image_(sc.yRes_, sc.xRes_, sc.filename_)
{}

renderer::~renderer()
{}

void
renderer::render_scene() 
{
    camera* cam = sc_.cam_ptr;
    //window_.resize(sc_.xRes_, sc_.yRes_);
    for(std::size_t y = 0; y < sc_.yRes_; ++y)
    {
        for(std::size_t x = 0; x < sc_.xRes_; ++x)
        {
            // create pixel at x,y
            pixel p(x,y);

            point pp;
            pp[0] = x - 0.5 * sc_.xRes_; 
            pp[1] = y - 0.5 * sc_.xRes_; 

            ray r;
            r.origin_ = cam->get_eye();
            r.direction_ = cam->calc_eye_ray(pp);
            
            hitpoint closest;
            bool hit = false;
            point local_hitP;
            vector view;
            material* mat_ptr;
            double tmin = 5000000;

            for (auto it : sc_.shape_map)
            {
                if (it.second->intersect(r, closest))
                {
                    if (closest.t_ < tmin) 
                    {
                        hit = true;
                        local_hitP = closest.hitpoint_;
                        view = closest.view_;
                        tmin = closest.t_;
                        mat_ptr = closest.material_ptr_;
                    }
                }
            }

            if(hit)
            {
                p.rgb = color(1.0,0.0,0.0);
            }
            else 
            {
                p.rgb = color(0.0,0.0,0.0);
            }

            //write pixel to output window
            window_.write(p);

            // write pixel to image
            image_.write(p);
        }
    }

    // save final image
    image_.save();

}
