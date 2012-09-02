#include "../include/sdf_loader.hpp"
#include "../include/material.hpp"
#include "../include/point.hpp"
#include "../include/box.hpp"
#include "../include/sphere.hpp"
#include "../include/light.hpp"
#include "../include/camera.hpp"
#include "../include/renderer.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

using namespace math3d;

sdf_loader::sdf_loader(std::string file)
    :filename_(file), 
    scene_(scene())
{}

sdf_loader::~sdf_loader() {}

void 
sdf_loader::load_sdf_file() {
    
    std::cout << "Loading \"" << filename_ << "\"..." << std::endl;

    std::fstream sdf_file;
    sdf_file.open(filename_.c_str(), std::ios::in);
    
    if(!sdf_file) {
        std::cerr << "ERROR!" << std::endl;
        std::cerr << "Could not open file!" << std::endl;
        
        return;
    }

    if(sdf_file.is_open()) {

        while(!sdf_file.eof()) {
            std::string sdf_line;
            std::getline(sdf_file, sdf_line);   //get line from sdf_file
            std::stringstream ss;
            ss << sdf_line;     //streams lines in stringstream

            std::string keyword;
            ss >> keyword;
            if(keyword == "define") 
            {
                std::string mode;
                ss >> mode;
                if(mode == "material") 
                {
                    std::string name;
                    float r, g, b;
                    ss >> name >> r >> g >> b;
                    color ka(r, g, b);

                    float r1, g1, b1;
                    ss >> r1 >> g1 >> b1;
                    color kd(r1, g1, b1);

                    float r2, g2, b2;
                    float m;
                    ss >> r2 >> g2 >> b2 >> m;
                    color ks(r2, g2, b2);
                    material* mat_ptr = new material 
                                        (name, ka, kd, ks, m);
                    //scene_.material_map.insert(std::pair<std::string, 
                    //material>(name, m1));
                    scene_.material_map[name] = mat_ptr;
                }

                if(mode == "shape") 
                {
                    std::string shapemode;
                    ss >> shapemode;
                    if(shapemode == "box") 
                    {
                        std::string name;
                        double x1, y1, z1;
                        ss >> name >> x1 >> y1 >> z1;
                        point p1(x1, y1, z1);

                        double x2, y2, z2;
                        ss >> x2 >> y2 >> z2;
                        point p2(x2, y2, z2);
                        
                        std::string mat;
                        ss >> mat;

                        material boxmat;
                        for (auto i : scene_.material_map) 
                        {
                            if(mat == i.first) 
                            {
                                boxmat = *i.second;
                            }
                        }
                        material* boxmat_ptr = new material (boxmat);
                        shape* ptr = new box (name, p1, p2, boxmat_ptr);
                        scene_.shape_map.insert(std::pair<std::string, 
                                shape*>(name, ptr));
                    }
                    
                    if(shapemode == "sphere") 
                    {
                        std::string name;
                        double x1, y1, z1;
                        ss >> name >> x1 >> y1 >> z1;
                        point center(x1, y1, z1);

                        double radius;
                        ss >> radius;
                        
                        std::string mat;
                        ss >> mat;

                        material sphmat;
                        for (auto i : scene_.material_map) 
                        {
                            if(mat == i.first) 
                            {
                                sphmat = *i.second;
                            }
                        }
                        material* sphmat_ptr = new material (sphmat);
                        shape* ptr = new sphere (name, center, radius, 
                                sphmat_ptr);
                        scene_.shape_map.insert(std::pair<std::string, 
                                shape*>(name, ptr));
                    }
                }

                if(mode == "light") 
                {
                    std::string name;
                    double x, y, z;
                    float r,g, b;
                    ss >> name >> x >> y >> z >> r >> g >> b;
                    point pos(x,y,z);
                    color La(r,g,b);
                    
                    float r1, g1, b1;
                    ss >> r1 >> g1 >> b1;
                    color Ld(r1,g1,b1);

                    Light* light_ptr = new Light (name, pos, La, Ld);
                    scene_.light_map[name] = light_ptr;
                }
                
                if(mode == "camera") 
                {
                    std::string name;
                    float fovX;
                    double x,y,z;;
                    ss >> name >> fovX >> x >> y >> z;
                    point pos(x,y,z);

                    camera* camptr = new camera (name, fovX);
                    scene_.cam_ptr = camptr;
                }
            }

            if (keyword == "render")
            {
                std::string name;
                std::string filename;
                std::size_t xRes, yRes;

                ss >> name >> filename >> xRes >> yRes;
                scene_.filename_ = filename;
                scene_.xRes_ = xRes;
                scene_.yRes_ = yRes;
            }
        }
        
        sdf_file.close();
    }
}

scene const& 
sdf_loader::get_scene() const
{
    return scene_;
}

std::ostream& 
operator<<(std::ostream& os, sdf_loader const& obj) {
    obj.print_on(os);
    return os;
}

void sdf_loader::print_on(std::ostream& os) const {
    os << scene_;
}

