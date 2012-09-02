#include <iostream>

#include "../include/scene.hpp"
#include "../include/light.hpp"
#include "../include/material.hpp"
#include "../include/shape.hpp"
#include "../include/camera.hpp"

scene::scene() 
    :material_map(), 
    shape_map() 
{}
    
scene::~scene() 
{}


void scene::print_on(std::ostream& out) const 
{
    for(auto i : material_map) 
    {
        out << *(i.second);
        std::cout << std::endl;
    }

    for(auto i : shape_map) 
    {
        out << *(i.second);
        std::cout << std::endl;
    }

    for(auto i : light_map) 
    {
        out << *(i.second);
        std::cout << std::endl;
    }

    out << (*cam_ptr);
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out, scene const& scn) {
    scn.print_on(out);
    return out;
}
